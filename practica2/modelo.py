from datetime import datetime

class Vehiculo:
    def __init__(self, placa, modelo):
        self.placa = placa.upper()
        self.modelo = modelo

class Carro(Vehiculo):
    def __init__(self, placa, modelo):
        super().__init__(placa, modelo)
        self.tipo = "Carro"
        self.tarifa = 20.0

class Moto(Vehiculo):
    def __init__(self, placa, modelo):
        super().__init__(placa, modelo)
        self.tipo = "Motocicleta"
        self.tarifa = 10.0

class Estacionamiento:
    def __init__(self, capacidad=10):
        self.capacidad = capacidad
        self.lugares_ocupados = {}

    def registrar_entrada(self, vehiculo):
        if len(self.lugares_ocupados) < self.capacidad:
            self.lugares_ocupados[vehiculo.placa] = vehiculo
            return True
        return False

    def registrar_salida(self, placa):
        return self.lugares_ocupados.pop(placa.upper(), None)