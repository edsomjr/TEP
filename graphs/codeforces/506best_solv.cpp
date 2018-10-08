#include<bits/stdc++.h>
#define int64 long long
#define sqr(x) (x)*(x)
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i, x, y) for(int i=(x);i<=(y);++i)
#define VI vector<int>
#define VI64 vector<int64>
#define VS vector<string>
#define PII pair<int,int>
#define PDD pair<double,double>
#define VPII vector< PII >
#define SZ(x) ((int)(x).size())
#define N 110000
using namespace std;
const double pi=acos(-1);
int n, m, Q, tot, cnt;
int ans[N], u[N], v[N], id[N], colors_count[N], component[N], q[N], f[N];
VPII edge[N];
VI E[N], D[N];

void dfs (int x) {
	if (component[x]) return;
	component[x] = cnt;
	for (int i : E[x]) dfs(i);
}

int main() {
	scanf("%d %d", &n, &m);
	rep (i, 1, m) {
		int x, y, k;
		scanf("%d %d %d", &x, &y, &k);
		edge[k].pb({x, y});
		colors_count[k]++;
	}

	scanf("%d", &Q);

	rep (i, 1, Q) {
		scanf("%d %d", &u[i], &v[i]);
		if (u[i] > v[i])
			swap(u[i], v[i]);
	}
	
	int mm = sqrt(m);

	// à priori suponho que ele faça isso pra não ter que ordenar (?)
	rep (i, 1, m) {
		if (colors_count[i] > mm) {
			// faz um grafo a partir das arestas
			// ex:
			/* 4 5
			   1 2 1
			   1 2 2
			   2 3 1
			   2 3 3
			   2 4 3
			   em colors_count[3] (= 2), faria-se e[2]=3; e[3]=2; e[2]=3,4; e[4]=2
			*/
			rep (j, 0, colors_count[i]-1) {
				int x = edge[i][j].fi, y = edge[i][j].se;
				E[x].pb(y);
				E[y].pb(x);
			}

			// navega por todos os componentes
			rep (j, 1, n) {
				if (!component[j]) cnt++;
				dfs(j);
			}

			// se pertencem ao mesmo componente, nessa cor
			// existe *um* caminho entre A e B (requisitados pelas querys) 
			rep (j, 1, Q)
				if (component[u[j]] == component[v[j]])
					ans[j]++;

			// reseta tudo para o proximo loop
			rep (j, 1, n) 
				E[j].clear();

			fill (component, component+N, 0);
		}
	}
	
	rep (i, 1, m) {
		if (colors_count[i] <= mm) {
			tot = 0;
			rep (j, 0, colors_count[i]-1) {
				int x = edge[i][j].fi, y = edge[i][j].se;
				q[++tot] = x;
				q[++tot] = y;
				E[x].pb(y);
				E[y].pb(x);
			}

			// q é, simplesmente, um set com todos os vertices conectados à cor[i]
			// pq nao usar set? pq nao é possivel utilizar o operador []
			// tot é o tamanho do set
			sort(q+1, q+tot+1);
			tot = unique(q+1, q+tot+1)-q-1;
			
			// navega por todos os vertices desse set contabilizando os componentes
			// * pq ele nao faz o mesmo set no for de cima?
			rep (j, 1, tot) {
				if (!component[q[j]]) cnt++;
				dfs(q[j]);
			}

			// * nao esta utilizando os vertices A e B das querys Q...
			
			// se set = {1, 2, 3, 4}
			// loop sera:
			// {1, 2}, {1, 3}, {1, 4}
			// {2, 3}, {2, 4}
			// {3, 4}

			// se pertencem ao mesmo componente (e sao da mesma cor), 
			// forma grafo unidirecional (por que?) saindo do menor para o maior
			rep (j, 1, tot) {
				rep (k, j+1, tot) {
					if (component[q[j]] == component[q[k]]) {
						D[q[j]].pb(q[k]);
					}
				}
			}

			// reseta tudo
			rep (j, 1, tot) {
				component[q[j]] = 0;
				E[q[j]].clear();
			}
		}
	}
	
	rep (i, 1, Q)
		id[i] = i;

	// o mesmo que ordenar um par baseado no primeiro elemento
	// o par no caso é A e B (u e v) das querys Q
	sort (id+1, id+Q+1, [&](const int i, const int j) {
		return u[i] < u[j];
	});

	int j = 1;

	rep (i, 1, n) {
		// se o i é diferente da ordenaçao anterior, continua
		if (j <= Q && u[id[j]] != i) 
			continue;

		// conta a frequencia de cada vertice
		for (int k : D[i]) 
			f[k]++;

		// soma a freq apenas do maior
		while (j <= Q && u[id[j]] == i) {
			ans[id[j]] += f[v[id[j]]];
			j++;
		}

		for (int k : D[i]) {
			f[k] = 0;
		}
	}

	rep (i, 1, Q)
		printf("%d\n",ans[i]);
}