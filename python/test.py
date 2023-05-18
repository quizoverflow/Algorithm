class Country:
    nation = ""
    popular = 0
    def __init__(self,val1, val2):
        self.nation = val1
        self.popular = val2
    
    def display(self):
        print(f"국가명: {self.nation}")
        print(f"인구수: {self.popular}")

class NewCountry(Country):
    capital =""

    def __init__(self,val1,val2,val3):
        self.nation = val1
        self.popular =val2
        self.capital = val3
    
    def display(self):
        super().display()
        print(f"수도명: {self.capital}")
    






aCountry = Country('Korea', 5000)
bCountry = NewCountry('NewWorld', 5000, 'Seoul')
aCountry.display()
bCountry.display()