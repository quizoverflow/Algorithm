class Country:
    name = ""
    population = ""

    #def __init__(self, name, population):
        #self.name = 0
        #self.population = 0        ...이건 뭐임?? 형변환까지 해버렸네??

    def display(self):
        print(f"국가명 : {self.name}, 인구수 : {self.population}")

class NewCountry(Country):
    capital = ""

    #def __init__(self, name, population, capital):
    #    self.capital = 0

    def display(self):
        print(f"국가명 : {self.name}, 인구수 : {self.population}, 수도명 : {self.capital}")


aCountry = Country()
aCountry.name = 'Korea'
aCountry.population = 5000

bCountry = NewCountry() #클래스의 인자는 함수의 인자라고 생각하면 안됨
bCountry.name = 'NewWorld'
bCountry.population = 5000
bCountry.capital = 'Seoul'

aCountry.display()
bCountry.display()