import re
import pandas as pd
from typing import List
from rocket import RocketEvent
from pandas import DataFrame

event_regex = r" (?P<event_name>[A-Z_]+)* occurred at t=(?P<time>[\d\.]+) seconds"


class OpenRocketDataParser:
    data_dict: dict = {}
    data_table: pd.DataFrame = DataFrame()
    rocket_events: List[RocketEvent] = []

    def __init__(self, file_name):
        with open(file_name, newline='') as f:
            lines = f.readlines()
            column_names = lines[0]

            # format column names into snake_case
            column_names = [item[:item.rfind(" ")].replace(" ", "_").replace("(", "").replace(")", "").lower()
                            for item in column_names.strip("# \n").split(",")]

            data = {}  # construct dictionary from data

            for line in lines[1:]:
                if line.startswith("#"):  # is a comment
                    matches = re.search(event_regex, line)
                    rocket_event = RocketEvent()
                    rocket_event.name = matches.group("event_name")
                    rocket_event.time = float(matches.group("time"))
                    if rocket_event.name and rocket_event.time:  # the comment describes an event
                        print(rocket_event)
                        self.rocket_events.append(rocket_event)
                    continue

                i = 0
                for value in line.split(","):
                    column_name = column_names[i]
                    data.setdefault(column_name, []).append(float(value))
                    i += 1

            self.data_dict = data
            self.data_table = pd.DataFrame(data)

    def plot_all(self):
        self.data_table.plot()

    def get_table(self) -> DataFrame:
        return self.data_table

    def get_dict(self) -> dict:
        return self.data_dict

    def get_events(self) -> List[RocketEvent]:
        return self.rocket_events


parser = OpenRocketDataParser("../OpenRocketSimulation_SRM_1-5.csv")
parser.plot_all()
