# Colonia-de-hormigas 🐜

El algoritmo de colonia de hormigas, inspirado en el comportamiento de las colonias de hormigas en la naturaleza, es una técnica de optimización que se utiliza para resolver problemas complejos. El algoritmo simula el comportamiento colectivo de las hormigas al buscar rutas más cortas entre la fuente de alimento y el nido, aplicando este concepto a problemas de optimización en diferentes dominios.

El algoritmo comienza con una población de hormigas virtuales que exploran el espacio de búsqueda y depositan feromonas en su camino. Las feromonas actúan como una señal química que indica la calidad de las soluciones encontradas. A medida que las hormigas avanzan, la intensidad de las feromonas aumenta en las rutas más cortas y disminuye en las rutas más largas.

Las hormigas se guían por las feromonas para seleccionar sus movimientos posteriores. Existe una mayor probabilidad de que una hormiga siga una ruta con una concentración más alta de feromonas, lo que a su vez atrae a más hormigas a esa ruta. Con el tiempo, las rutas más cortas acumulan más feromonas y se vuelven aún más atractivas para las hormigas, lo que crea un efecto positivo de retroalimentación.

A medida que las hormigas encuentran soluciones prometedoras, la información sobre estas soluciones se comparte globalmente en la colonia, lo que permite una exploración más efectiva del espacio de búsqueda. Esto mejora la capacidad del algoritmo para encontrar soluciones óptimas o subóptimas en función de la calidad de las feromonas depositadas.

El algoritmo de colonia de hormigas se ha utilizado con éxito en una variedad de problemas, como el enrutamiento de vehículos, la planificación de rutas, la asignación de tareas y la optimización de redes, entre otros. Su capacidad para encontrar soluciones aproximadas eficientes en problemas complejos lo convierte en una poderosa herramienta de optimización inspirada en la naturaleza.

En este algorimo se utiliza la liobreria fri26.tsp de TSPLIB 95
