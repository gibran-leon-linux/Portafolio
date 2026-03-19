# Clases
class estacionamiento:
    # Variables
    def variables(estacionamiento, spots, vehiculo, tickets):
        estacionamiento.spots = spots
        estacionamiento.vehiculo = vehiculo
        estacionamiento.tickets = tickets
    # Metodos
    def reg_Entrada(estacionamiento):
        print("Registre el tiempo de entrada del carro")
    
    def reg_Salida(estacionamiento):
        print("Registre el tiempo de salida del carro")
    
    def calcular_Cobro(estacionamiento):
        print("Calcular el cobro del estacionamiento")
    
    def mostrar_Estado(estacionamiento):
        print("Mostrar si el espacio esta ocupado o no")
        
# Main
"""
REQUISITOS:
Implementar clases y objetos para representar el sistema de estacionamiento, sus clases y objetos.
Incluir herencia, encapsulamiento, abstracción y polimorfismo.
Menú de texto para interacción en consola al inicio e interfaz web al final.
"""

