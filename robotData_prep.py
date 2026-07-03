import pandas as pd

data = {
    "Package_ID": ["P1", "P2", "P3", "P4"],
    "Target_X": [3, -2, 4, 0],
    "Target_Y": [4, 1, -3, 5],
    "Weight_KG": [12.5, 3.2, 25.0, 1.8]
}

robotData = pd.DataFrame(data)

sortedData = robotData.sort_values(by="Weight_KG")

print(sortedData)

sortedData.to_csv("robotPackages.csv", index=False)