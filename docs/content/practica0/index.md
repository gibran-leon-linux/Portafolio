+++
date = '2026-02-19T23:48:09-08:00'
draft = false
title = 'Práctica 0: Uso De Repositorios'
+++

## MARKDOWN

### ¿QUÉ ES?
Markdown o MD es un lenguaje de marcado ligero creado por John Gruber.
Permite escribir documentos en un formato de texto plano, fácil de leer, escribir,
y luego convertirlos en documentos HTML válidos.

### ¿CÓMO SE UTILIZA?
Markdown se utiliza en muchos lugares donde es necesario dar estilo o estructurar texto plano.
Los desarrolladores y redactores técnicos a menudo usan Markdown para escribir documentación debido 
a su legibilidad y fácil integración con sistemas de control de versiones como Git.

GitHub adoptó Markdown como formato predeterminado para los archivos Readme y proporcionó una especificación de renderizado. Con la expansión de GitHub, cada vez más desarrolladores empezaron a usar Markdown como su herramienta preferida para escribir.

Muchos generadores de sitios estáticos modernos como Jekyll, Hugo y Next.js admiten Markdown para la creación de contenido. También lo utilizan plataformas de blogs como Ghost y Dev.to.

Aplicaciones como Obsidian, Notion y Bear permiten a los usuarios escribir notas utilizando la sintaxis de Markdown para facilitar el formateo.

Algunos clientes de correo electrónico y plataformas de mensajería permiten sintaxis Markdown parcial para formato básico como negrita, cursiva o bloques de código.

Markdown también se utiliza en plataformas donde su objetivo es compartir texto, como, por ejemplo, la plataforma de Wordpress.

### SINTAXIS
### Encabezado:

# H1 - Título principal
## H2 - Título de sección
### H3 - Título de subsección

### Textos:

*Texto en cursiva* 

**Texto en negrita**

***Negrita y cursiva***

### Listas:
1. Elemento 1
2. Elemento 2
3. Elemento 3
    1. Elemento 3.1
    2. Elemento 3,2

### Enlaces:

[Texto del enlace](https://www.google.com "Texto del tooltip")

### Linea Horizontal:

---

### Texto que puede ser codigo:
    
    **EJEMPLO DE CODIGO**
    void ejemplo()
    {

    }

## GIT

### ¿QUÉ ES?
Sistema de control de versiones distribuido para llevar el historial de cambios de archivos.
### ¿CÓMO SE UTILIZA?
Permite trabajar localmente con commits, ramas y fusiones, y coordinar cambios entre varios desarrolladores.
### COMANDOS
git init

git clone <url-del-repositorio>

git status

git add <archivo>        

git add .

git commit -m "Mensaje descriptivo"

git branch

git remote -v

git remote add origin <url>

git push origin nombre-rama

git pull origin nombre-rama

git log

git diff

## GITHUB

### ¿QUÉ ES?
Plataforma en la nube para alojar repositorios Git, colaborar, revisar código y desplegar proyectos.
### ¿CÓMO SE UTILIZA?
Es un servicio que usa Git como motor de control de versiones.

Crear repo en GitHub

Clonar a local o añadir origin si ya existe local

Crear una rama para la tarea/feature

Hacer commits locales regularmente

Push de la rama

Abrir Pull Request en GitHub para revisión

Revisar y fusionar PR en la rama principal

Actualizar tu rama local

### COMANDOS
git config --global user.name "Tu Nombre"

git config --global user.email "tu@correo"

git init

git clone <url>

git status

git add .

git commit -m "Mensaje"

git branch

git checkout -b rama

git merge rama

git remote -v

git remote add origin <url>

git push origin rama

git pull origin rama

git log --oneline

git diff

git reset HEAD archivo

git revert <hash>

## HUGO Y GITHUB ACTIONS
### ¿QUÉ ES HUGO?
Es un generador de sitios estáticos. A diferencia de CMS tradicionales, no depende de bases de datos ni de un backend complejo ya que convierte nuestros archivos de contenido markdown y las plantillas en un sitio web completamente estático, listo para publicar en cualquier servidor o servicio de hosting estático.

### ¿QUÉ ES GUTHUB ACTIONS?
Es una plataforma de Integración Continua (CI) y Entrega Continua (CD) que te permite automatizar cada paso del ciclo de vida del software.

### CREAR UN SITIO EN HUGO
Para crear un sitio web con Hugo, es importante tener los prerrequisitos instalados, y luego podemos ejecutar el comando:

hugo new site first-site

### SUBIR PAGINA A GITHUB ACTIONS
Crea un repositorio en GitHub
Agregar un token de acceso personal
Configuración de GitHub Actions
Configuración en Hostinger
Accede al panel de control de Hostinger
Configura el acceso FTP
Preparar el servidor para despliegue
Automatizar la Subida a Hostinger
Configurar Secretos FTP en GitHub

### SUBIR EL SITIO A GITHUB
En el directorio de tu proyecto Hugo, crea un archivo llamado 
.github/workflows/deploy.yml y agrega el siguiente contenido:

on:
  push:
    branches:
      - main

jobs:
  deploy:
    runs-on: ubuntu-20.04
    steps:
      - uses: actions/checkout@v2
        with:
          submodules: true
          fetch-depth: 0

name: Setup Hugo
        uses: peaceiris/actions-hugo@v2
        with:
          hugo-version: '0.126.2'
          extended: true

name: Build
        run: hugo --minify

name: Deploy
        uses: peaceiris/actions-gh-pages@v3
        with:
          github_token: ${{ secrets.GH_TOKEN }}
          publish_branch: deployed
          publish_dir: ./public

## ENLACES

-[Github](https://github.com/gibran-leon-linux?tab=repositories "Github")

-[Pagina Hugo](https://www.google.com "Hugo")