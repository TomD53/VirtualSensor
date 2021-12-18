from arduino import VirtualSensorServer
from simulation import *
from math import sin


class MySimulation(Simulation):
    name = "Tom's simulation"

    def get_value(self, request: SensorRequest):
        time_since_start = self.get_time_elapsed()
        return sin(time_since_start)


sim = MySimulation()
VirtualSensorServer("COM5", ["BME280"], simulation=sim, debug=True)
