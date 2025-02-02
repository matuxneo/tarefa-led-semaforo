# Projeto: LED semáforo Tarefa

## Descrição
Este projeto implementa um semáforo utilizando a placa BitDogLab com o microcontrolador RP2040. O semáforo alterna entre os estados vermelho, amarelo e verde em intervalos de tempo definidos. O código está localizado no arquivo `matrizrgbtarefa.c`.

## Como Rodar o Projeto

Para rodar o projeto localmente, siga os seguintes passos:

### 1. Clone o repositório:
```sh
 git clone https://github.com/Daniel24060/tarefa-led-semaforo.git
```

### 2. Entre na pasta do projeto:
```sh
 cd tarefa-led-semaforo
```

## Instruções para Configuração e Compilação do Projeto

### Passo 1: Baixar o Ninja
Acesse a página oficial de releases do Ninja:
[Ninja Releases no GitHub](https://github.com/ninja-build/ninja/releases)

- Baixe o arquivo binário mais recente para Windows (geralmente um .zip).
- Extraia o conteúdo do arquivo .zip (haverá um arquivo `ninja.exe`).

### Passo 2: Adicionar o Ninja ao Path do sistema
Para que o `ninja` seja reconhecido como um comando em qualquer terminal, siga estas etapas:

1. Clique com o botão direito no botão Iniciar e selecione **Configurações**.
2. Vá em **Sistema** → **Sobre** → **Configurações avançadas do sistema** (no lado direito).
3. Na aba **Avançado**, clique em **Variáveis de Ambiente**.
4. Na seção **Variáveis do Sistema**, localize a variável `Path` e clique em **Editar**.
5. Clique em **Novo** e adicione o caminho completo para o diretório onde você extraiu o `ninja.exe`, por exemplo:
   ```
   C:\Users\SeuUsuario\Downloads\ninja-win
   ```
6. Clique em **OK** em todas as janelas.

### Passo 3: Verificar se o Ninja está funcionando
Abra um terminal (PowerShell ou Prompt de Comando) e digite o comando abaixo para verificar a instalação:
```sh
ninja --version
```

### Passo 4: Configurar e Compilar o Projeto
Volte ao diretório do projeto e abra um terminal.

1. Crie ou limpe a pasta `build`:
   ```sh
   rmdir /s /q build
   mkdir build
   cd build
   ```

2. Configure o projeto com o CMake:
   ```sh
   cmake -G Ninja ..
   ```

3. Compile o projeto:
   ```sh
   ninja
   ```

Após isso, o arquivo `main.elf` será gerado na pasta `build`.

## Simulação no Wokwi

Após a configuração, você pode usar o simulador Wokwi para testar o circuito.
- Acesse o simulador através do link [Wokwi](https://wokwi.com/)
- Ou use a extensão do Wokwi no VSCode: [Wokwi VSCode](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode)

Veja como a interação com os botões aciona os LEDs e como os estados do semáforo são alternados automaticamente.

Após isso é só iniciar a simulação no wokwi integrado ao vs code.
