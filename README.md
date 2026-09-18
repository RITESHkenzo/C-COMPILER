hello.c
   │
   ▼
┌──────────────┐
│    Lexer     │   characters → tokens
└──────┬───────┘
       ▼
┌──────────────┐
│    Parser    │   tokens → AST
└──────┬───────┘
       ▼
┌──────────────┐
│   Semantic   │   types, variables, scopes
│   Analysis   │
└──────┬───────┘
       ▼
┌──────────────┐
│ Code Generator│  AST → x86-64 assembly
└──────┬────────┘
       ▼
    program.s
       │
       ▼
 assembler/linker
       │
       ▼
    executable

