from flask import Flask, render_template, request, redirect, url_for
from modelo import Estacionamiento, Carro, Moto

app = Flask(__name__)
parking = Estacionamiento(capacidad=10)

@app.route('/')
def index():
    return render_template('index.html', carros=parking.lugares_ocupados)

@app.route('/entrada', methods=['POST'])
def entrada():
    p = request.form['placa']
    m = request.form['modelo']
    t = request.form['tipo']
    v = Carro(p, m) if t == "Carro" else Moto(p, m)
    parking.registrar_entrada(v)
    return redirect(url_for('index'))

@app.route('/salida/<placa>')
def salida(placa):
    parking.registrar_salida(placa)
    return redirect(url_for('index'))

if __name__ == '__main__':
    app.run(debug=True)