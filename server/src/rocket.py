class RocketEvent:
    name: str
    time: int

    def __str__(self):
        return f"RocketEvent(name={self.name}, time={self.time})"


class RocketEventGoal:
    event: RocketEvent
    time_margin: int
    success: bool = False
