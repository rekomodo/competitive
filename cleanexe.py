import os

dirName = "C:/Users/Jair/Desktop/Programmy Stuff/competitive/"
test = os.listdir(dirName)

for item in test:
    if item.endswith(".exe"):
        os.remove(os.path.join(dirName, item))
