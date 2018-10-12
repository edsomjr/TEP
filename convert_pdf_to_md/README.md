# Convert PDF to MD

Este não é um 'conversor' de propósito geral, sendo adequado somente para os slides [aqui](https://github.com/edsomjr/TEP/tree/master/Grafos) presentes.

# Como utilizar

1. Primeiro inicie um servidor [Tika](https://tika.apache.org/) em outro terminal
```console
~$ java -jar tika-server-1.19.jar -h 0.0.0.0
```

1. Passe os parâmetros para o script **run.sh**:
    1. PDF
    1. Última página do pdf (normalmente o de *Referências*)
    1. Tema do PDF
    1. Número de "visualizações" no PDF
    1. N pares (início e fim da visualização X) de páginas

    Exemplo de utilização:
    ```console
    ~$ bash run.sh STV-3.pdf 48 "bipartite" 3 3 13 18 24 32 44
    ```
    
