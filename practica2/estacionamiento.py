

# Clases
class carro:
    # Variables
    def variables(carro, spot, vehiculo, ticket):
        carro.spot = spot
        carro.vehiculo = vehiculo
        carro.ticket = ticket
    # Metodos
    def prueba(carro):
        print("|DATOS|", end="")
        print(f,"|Spot: {spot}|Vehiculo: {vehiculo}|Ticket: {ticket}|", end="")
        
    def reg_Entrada(carro):
        print("Entrada")
        
    def reg_Salida(carro):
        print("Salida")
        
    def calcular_Cobro(carro):
        print("Cobro")
        
    def mostrar_Estado(carro):
        print("Estado")

# Asignar spot si hay espacio disponible
# Asignar vehiculo al spot si el ticket es valido
# Ticket bool 0 inactivo 1 activo
carro1 = carro(None,"Nissan March",0)
carro2 = carro(None,"Honda Civic",0)
carro3 = carro(None,"Honda Fit",0)
carro4 = carro(None,"Nissan Versa",0)
carro5 = carro(None,"Chevrolet Camaro",0)

# Main
"""
REQUISITOS:
Implementar clases y objetos para representar el sistema de estacionamiento, sus clases y objetos.
Incluir herencia, encapsulamiento, abstracción y polimorfismo.
Menú de texto para interacción en consola al inicio e interfaz web al final.
"""

carro1.prueba()

