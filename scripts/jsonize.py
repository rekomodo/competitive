import json

with open(file="test1.cpp", mode="r") as source:
    with open(file="output.json", mode="w") as output:
        # json.dump(source.read().splitlines(), output)

        sauce = source.read().splitlines()
        toEscape = ("\\", "\"")  # order matters, \ must be escaped first
        for c in toEscape:
            sauce = [line.replace(c, f"\\{c}") for line in sauce]
        sauce = "\",\n\"".join(sauce)
        sauce = f"[\n\"{sauce}\"\n]"
        output.writelines(sauce)
