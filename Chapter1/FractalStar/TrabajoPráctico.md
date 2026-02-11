# Trabajo Práctico
Analizar FractalStar en el repositorio.
### - Explicar como funciona, cómo se genera la figura (de adelante hacia atras?)
Primero lee el ancho y el alto del lienzo (canvas) que previamente fue definido al crearlo.  
A partir de éstas medidas, calcula el centro de la imagen (cx y cy) y el radio inicial (r = ancho/8).  
Luego se va llamando recursibamente star() hasta que r llega a 1 (cada llamada divide r en 2).  
En ese momento hace las otras tres invocaciones a star(), y dibuja un cuadrado de 2x2 blanco con borde azul.  
La figura se genera de atrás a adelante, empezando por los cuatro extremos y convergiendo en el centro.
### - Que hace cada invocación (elimine partes y pruebe)
Cada invocación hace que la figura empieze desde cada uno de los 4 extremos. La 1ra abajo a la izq, la 2da
abajo a la derecha, y así.
### - Cambiar a preorden, cual es su efecto?
Cambiando a preorden, dibuja los cuadrados de adelante hacia atrás, lo que hace que las iteraciones vayan "pisando" lo ya dibujado.
