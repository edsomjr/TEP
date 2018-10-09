# Convert PDF to MD

Este não é um 'conversor' de propósito geral, sendo adequado somente para os slides [aqui](https://github.com/edsomjr/TEP/tree/master/Grafos) presentes.

# Como utilizar

1. Primeiro inicie um servidor [Tika](https://tika.apache.org/) em outro terminal
```console
~$ java -jar tika-server-1.19.jar -h 0.0.0.0
```

1. Passe os parâmetros para o script **run.sh**:
    1. PDF
    1. Primeira página de visualização ([como essa](SSP-2/images/out5.jpg))
    1. Última página de visualização
    1. Tema do PDF

    Exemplo de utilização:
    ```console
    ~$ bash run.sh SSP2.pdf 4 13 "bfs e dfs"
    ```
