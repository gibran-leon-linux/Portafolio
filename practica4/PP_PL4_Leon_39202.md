## INTRODUCCIÓN
El desarrollo de software moderno exige el conocimiento de diversos paradigmas de programación para resolver problemas de manera eficiente. Mientras que lenguajes como C se basan en instrucciones paso a paso, Haskell introduce el paradigma funcional, que es un enfoque que se centra en la aplicación de funciones matemáticas.

## PRACTICA
1. La configuración del entorno se realizó mediante GHCup, la herramienta oficial para la gestión de Haskell. El proceso incluyó la instalación de los siguientes componentes:

-GHC (Haskell Compiler): El compilador que transforma el código .hs en ejecutables binarios.

-Stack y Cabal: Herramientas de automatización y gestión de paquetes que permiten descargar librerías externas y compilar proyectos.

-Haskell Language Server: El motor que proporciona las librerías estándar y el soporte para el funcionamiento del compilador.

2. Funcionamiento de la Aplicación TODO

-La aplicación analizada es un sistema de gestión de tareas.

-Lib.hs: Define las funciones de manipulación de datos, utiliza funciones como take y drop para editar una lista.

-Main.hs: Gestiona la interacción con el usuario. Utiliza la función prompt para crear un ciclo recursivo que recibe comandos como + (agregar), - (eliminar), e (editar) y l (listar).

3. Ejecución del Proyecto

Para ejecutar la aplicación, se utiliza el comando stack run, el sistema requiere un archivo de configuración .env que especifica una URL de inicio, demostrando cómo Haskell puede interactuar con variables de entorno y recursos externos del sistema operativo.

## CONCLUSIONES
-Al no poder modificar variables existentes, se eliminan errores de memoria, un problema recurrente en el manejo de punteros en C.

-Funciones como deleteOne y reverseTodos demuestran que los ciclos tradicionales como for y while/doWhile pueden ser reemplazados por funciones recursivas que procesan listas de forma natural.

-Haskell permite escribir menos líneas de código para realizar operaciones complejas de listas, facilitando la legibilidad.

Esta práctica ayuda a comprender las bases para aprender el paradigma funcional.

## ENLACES

-[Github](https://github.com/gibran-leon-linux?tab=repositories "Github")

-[Pagina Hugo](https://gibran-leon-linux.github.io/Portafolio/ "Hugo")