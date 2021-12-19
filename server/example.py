from server import VirtualSensorServer
from simulation import *
from math import sin
from time import sleep

from virtualsensor.simulation import Simulation, SensorRequest


class MySimulation(Simulation):
    name = "Tom's simulation"

    def get_value(self, request: SensorRequest):
        time_since_start = self.get_time_elapsed()
        return sin(time_since_start)


sim = MySimulation()
server = VirtualSensorServer("COM5", ["BME280"], simulation=sim, debug=False, serial_monitor=False)
server.start()
sleep(5)
sim.start()
sleep(10)
sim.finish()
server.stop()
