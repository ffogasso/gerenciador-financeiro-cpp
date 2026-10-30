# Gerenciador Financeiro

Projeto de portfólio em C++ para aprender a desenvolver um sistema de organização
de finanças pessoais, com evolução incremental e controle de versão.

A versão **0.1.0** fornece a estrutura inicial e um executável que exibe uma
mensagem de boas-vindas. Ainda não há funcionalidades financeiras, persistência
ou testes automatizados.

## Objetivos

- Praticar C++ moderno e organização de código em arquivos separados.
- Aprender compilação com CMake e controle de versão com Git e GitHub.
- Evoluir o sistema em pequenas versões documentadas.
- Preparar a base para uma futura integração com SQLite.

## Tecnologias

- **C++17:** linguagem e padrão de compilação.
- **CMake 3.16 ou superior:** configuração da compilação.
- **Git:** controle de versão local.
- **GitHub:** hospedagem planejada do repositório.
- **SQLite:** persistência planejada para uma versão futura; não é dependência
  desta versão.

## Funcionalidades planejadas

- Cadastro de receitas e despesas.
- Acompanhamento de saldo e dívidas.
- Consultas e relatórios financeiros.
- Armazenamento local com SQLite.
- Testes automatizados conforme as regras do sistema forem implementadas.

Esses itens são planos de evolução e não estão implementados na versão 0.1.0.

## Estrutura de diretórios

```text
gerenciador-financeiro/
├── include/
│   └── .gitkeep
├── src/
│   └── main.cpp
├── tests/
│   └── .gitkeep
├── docs/
│   └── .gitkeep
├── .gitignore
├── CMakeLists.txt
├── README.md
├── CHANGELOG.md
└── LICENSE
```

- `src/main.cpp`: ponto de entrada do programa e mensagem de boas-vindas.
- `include/`: futuros cabeçalhos `.h` e `.hpp`.
- `tests/`: futuros testes automatizados.
- `docs/`: documentação complementar futura.
- `.gitkeep`: convenção para preservar pastas vazias no Git; pode ser removido
  quando a pasta receber conteúdo.
- `CMakeLists.txt`: nome e versão do projeto, fontes, cabeçalhos e padrão C++.
- `.gitignore`: impede o rastreamento de artefatos de compilação e arquivos locais.
- `README.md`: apresentação e instruções de uso do projeto.
- `CHANGELOG.md`: histórico de mudanças por versão.
- `LICENSE`: termos da licença MIT.

O diretório `build/` será criado durante a compilação e será ignorado pelo Git.
SQLite será integrado quando houver necessidade de persistência, sem estruturas
ou dependências adicionais nesta versão.

## Requisitos e instalação no Debian Linux

É necessário ter um compilador com suporte a C++17, CMake 3.16 ou superior e Git.
Para instalar as ferramentas:

```bash
sudo apt update
sudo apt install build-essential cmake git
```

`apt update` atualiza a lista de pacotes. `apt install` instala as ferramentas;
`build-essential` inclui o compilador G++ e o Make. `sudo` executa a instalação
com privilégios administrativos.

## Como compilar e executar

No terminal, entre na pasta do projeto e execute:

```bash
cd gerenciador-financeiro
cmake -S . -B build
cmake --build build
./build/gerenciador_financeiro
```

Se já estiver na raiz do projeto, pule o comando `cd`.

- `cmake -S . -B build`: lê o `CMakeLists.txt` da pasta atual e gera os arquivos
  de compilação dentro de `build/`.
- `cmake --build build`: chama a ferramenta de compilação configurada pelo CMake
  para compilar e vincular o executável.
- `./build/gerenciador_financeiro`: executa o programa gerado.

Saída esperada:

```text
Bem-vindo ao Gerenciador Financeiro!
```

Após modificar o código, execute novamente `cmake --build build`.

## Como funciona o CMake

`cmake_minimum_required` define a versão mínima da ferramenta. `project` declara
nome, versão `0.1.0` e linguagem C++. `add_executable` cria o alvo
`gerenciador_financeiro` a partir de `src/main.cpp`.

`target_include_directories` permite que esse alvo encontre cabeçalhos em
`include/`. O escopo `PRIVATE` aplica esse caminho ao próprio executável.
As propriedades `CXX_STANDARD`, `CXX_STANDARD_REQUIRED` e `CXX_EXTENSIONS` exigem
C++17 e desativam extensões específicas do compilador.

## Controle de versão

O projeto adota Versionamento Semântico (`MAJOR.MINOR.PATCH`) e mensagens no
formato Conventional Commits. A versão `0.1.0` identifica a base inicial do
projeto, ainda em desenvolvimento.

Para conferir arquivos novos e alterados:

```bash
git status
```

Sugestão de primeiro commit, a executar após revisar os arquivos:

```text
chore: initialize C++ project structure
```

Nesta etapa, nenhum commit, tag ou publicação no GitHub é feito automaticamente.

## Licença

Distribuído sob a [licença MIT](LICENSE).
Copyright (c) 2026 Filipe Fogasso.
