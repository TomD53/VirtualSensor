from time import time


class SensorRequest:
    sensor_name: str
    column_name: str

    def __init__(self, sensor_name, column_name):
        self.sensor_name = sensor_name
        self.column_name = column_name

    def __str__(self):
        return f"SensorRequest(sensor_name={self.sensor_name}, column_name={self.column_name})"


class Simulation:
    name: str = "UNNAMED SIMULATION"
    start_time: float = None  # in seconds

    def start(self):
        print(f"Starting simulation {self.name}")
        self.start_time = time()

    def get_time_elapsed(self):
        return time() - self.start_time if self.start_time else None

    def get_value(self, request: SensorRequest):
        return self.get_time_elapsed()

    def __str__(self):
        return f"Simulation(name={self.name}, start_time={self.start_time})"
