# LifeHub — Planejamento do Projeto

## Objetivo

Criar um sistema desktop de gerenciamento pessoal focado em:

- produtividade
- organização
- estudos
- hábitos
- controle do dia a dia

O projeto servirá tanto para uso pessoal quanto para aprendizado completo de:

- Programação Orientada a Objetos
- arquitetura de software
- frontend e backend
- banco de dados
- engenharia de software

---

# Tecnologias

## Backend
- C++

## Interface gráfica
- Qt

## Banco de dados
- SQLite

## Build System
- CMake

## Ferramenta para visualizar banco
- DB Browser for SQLite

---

# Objetivos de aprendizado

## Backend
- POO
- arquitetura
- separação de responsabilidades
- persistência
- CRUD
- serviços e controladores

## Frontend
- eventos
- formulários
- tabelas
- gráficos
- UI/UX
- comunicação entre telas

## Banco de dados
- SQL
- modelagem
- relacionamentos
- integração com aplicação

---

# Funcionalidades Planejadas

## Sistema de tarefas
- criar tarefas
- editar tarefas
- remover tarefas
- prioridade
- categorias
- status
- prazo
- tempo gasto

---

## Sistema de estudos
- registrar sessões de estudo
- assuntos estudados
- tempo estudado
- dificuldade
- progresso

---

## Sistema de hábitos
- academia
- leitura
- sono
- água
- estudos
- hábitos personalizados

---

## Dashboard
- tarefas do dia
- horas estudadas
- hábitos concluídos
- produtividade semanal
- estatísticas gerais

---

## Estatísticas
- gráficos
- streaks
- tempo por categoria
- produtividade semanal/mensal
- matérias mais estudadas

---

# Estrutura do Projeto

```txt
LifeHub/
│
├── src/
│   ├── models/
│   ├── services/
│   ├── controllers/
│   ├── database/
│   ├── ui/
│   └── main.cpp
│
├── assets/
├── database/
├── include/
├── CMakeLists.txt
└── README.md
```

---

# Arquitetura

## Models
Representam os dados da aplicação.

Exemplo:
- Task
- Habit
- StudySession

---

## Services
Contêm regras de negócio.

Exemplo:
- TaskService
- HabitService

---

## Controllers
Fazem comunicação entre interface e backend.

---

## Database
Responsável pela integração com SQLite.

---

## UI
Telas e componentes gráficos usando Qt.

---

# Caminho de aprendizado

## Etapa 1 — C++ + POO
Aprender:
- classes
- encapsulamento
- herança
- composição
- modularização

---

## Etapa 2 — Qt básico
Aprender:
- janelas
- botões
- eventos
- layouts
- formulários

---

## Etapa 3 — SQLite
Aprender:
- SQL básico
- CRUD
- persistência
- salvar e carregar dados

---

## Etapa 4 — Integração total
Objetivo:
- frontend chama backend
- backend salva no banco
- banco retorna dados para interface

---

# Objetivo final

Criar uma aplicação desktop bonita, organizada e realmente útil para o dia a dia, enquanto aprende desenvolvimento de software de forma prática e profissional.