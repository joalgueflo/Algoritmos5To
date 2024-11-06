

# Se nos da una matriz de asteroides de números enteros que representan asteroides en una fila.

# Para cada asteroide, el valor absoluto representa su tamaño y el signo representa su dirección (positivo a la derecha, negativo a la izquierda). Cada asteroide se mueve a la misma velocidad.

# Averigua el estado de los asteroides después de todas las colisiones. Si dos asteroides se encuentran, el más pequeño explotará. Si ambos son del mismo tamaño, ambos explotarán. Dos asteroides que se mueven en la misma dirección nunca se encontrarán.

 

# Ejemplo 1:

# Entrada: asteroides = [8, -8]
# Salida: []
# Explicación: El 8 y el -8 chocan explotando entre sí.


def asteroid(asteroids):
    stack = []
    for asteroid in asteroids:
        while stack:
            #Asteroide top
            top = stack[-1]
            isLeft = asteroid < 0 # Checamos que sea negativo
            isRight = top > 0 # Checamos que sea positivo
            # Si se cumple la colision, seguimos
            if isLeft and isRight:
                #Si el asteroide actual es mas grande, destruimos top
                if top < -asteroid:
                    stack.pop()
                    continue
                #Si son iguales, se eliminan
                elif top == -asteroid:
                    stack.pop()
                break
            else:
                #Si no hay colision, añadimos al stack
                stack.append(asteroid)
                break
        else:
            stack.append(asteroid)
    return stack

asteroides_input = input()
asteroides = [int(x) for x in asteroides_input.split()]
print(asteroid(asteroides))
