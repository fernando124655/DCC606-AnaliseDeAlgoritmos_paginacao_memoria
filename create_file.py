string = "Deem graças ao Senhor, porque ele é bom, porque a sua misericórdia dura para sempre"*50000
with open("file-5mb.txt", "w") as file:
    file.write(string)
