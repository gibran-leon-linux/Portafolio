import os

class Vehiculo:
    def __init__(self, placa, modelo):
        self.placa = placa.upper()
        self.modelo = modelo
        self.tarifa = 0.0

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
        self.vehiculos = {}

    def registrar_entrada(self, vehiculo):
        if len(self.vehiculos) < self.capacidad:
            self.vehiculos[vehiculo.placa] = vehiculo
            print(f"{vehiculo.tipo} registrado con éxito.")
        else:
            print("Estacionamiento lleno.")

    def registrar_salida(self, placa):
        placa = placa.upper()
        if placa in self.vehiculos:
            v = self.vehiculos.pop(placa)
            print(f"Salida de {v.tipo} ({v.placa}). Total a pagar: ${v.tarifa}")
        else:
            print("Placa no encontrada.")

def menu():
    est = Estacionamiento()
    while True:
        print("\n--- ESTACIONAMIENTO ---")
        print("1. Entrada Carro\n2. Entrada Moto\n3. Salida y Pago\n4. Ver Status\n5. Salir")
        op = input("Seleccione opción: ")

        if op == "1":
            p = input("Placa: "); m = input("Modelo: ")
            est.registrar_entrada(Carro(p, m))
        elif op == "2":
            p = input("Placa: "); m = input("Modelo: ")
            est.registrar_entrada(Moto(p, m))
        elif op == "3":
            p = input("Ingrese placa para cobrar: ")
            est.registrar_salida(p)
        elif op == "4":
            print(f"\nOcupación: {len(est.vehiculos)}/{est.capacidad}")
            for p, v in est.vehiculos.items():
                print(f"[{v.tipo}] {p} - {v.modelo}")
        elif op == "5":
            break

if __name__ == "__main__":
    menu()