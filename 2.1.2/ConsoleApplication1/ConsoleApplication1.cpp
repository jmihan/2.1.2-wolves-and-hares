#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream in("input.txt", ios::in);
ofstream out("output.txt", ios::out);

class Animal
{
protected:
    int x, y; //координаты зверя
    int d;  //направление движения зверя
    int k; //постоянство зверя
    int now; //сколько ходов до смены направления
    int age; //возраст зверя
public:
    Animal() {}
    Animal(int x, int y, int d, int k) : x(x), y(y), d(d), k(k), age(0), now(k) {}
    ~Animal() {}
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
    int getd()
    {
        return d;
    }
    int getk()
    {
        return k;
    }
    int getAge()
    {
        return age;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    /*void registration(int x, int y, int d, int k)
    {
        this->x = x;
        this->y = y;
        this->d = d;
        this->k = k;
        age = 0;
        now = k;
        alive = true;
    }*/
    virtual void move(int height, int width) = 0;

    
};
class Wolf: public Animal
{
private:
    int countRab; //количество съеденных зайцев у волка
    int ageParent; //возраст родителя
public:
    Wolf() : countRab(0), Animal(0,0,0,0), ageParent(-1) {}
    Wolf(int x, int y, int d, int k, int age) : countRab(0), Animal(x, y, d, k), ageParent(age) {}
    ~Wolf() {}
    void setRab(int c)
    {
        this->countRab = c;
    }
    int getAteRab()
    {
        return countRab;
    }
    int getAgeParent()
    {
        return ageParent;
    }
    void move(int height, int width)
    {
        switch (d)
        {
        case 0:
            switch (y)
            {
            case 0:
                y = height - 2;
                break;
            case 1:
                y = height - 1;
                break;
            default:
                y -= 2;
                break;
            }
            break;
        case 1:
            if (x == (width - 2))
            {
                x = 0;
            }
            else
            {
                if (x == (width - 1))
                {
                    x = 1;
                }
                else
                {
                    x += 2;
                }
            }
            break;
        case 2:
            if (y == (height - 2))
            {
                y = 0;
            }
            else
            {
                if (y == (height - 1))
                {
                    y = 1;
                }
                else
                {
                    y += 2;
                }
            }
            break;
        case 3:
            switch (x)
            {
            case 0:
                x = width - 2;
                break;
            case 1:
                x = width - 1;
                break;
            default:
                x -= 2;
                break;
            }
            break;
        }//switch
        now--;
        if(now == 0)
        {
            d++;
            if (d == 4)
            {
                d = 0;
            }
            now = k;
        }
        
    }
};
class Hyena : public Animal
{
private:
    int countAte; //количество съеденных зайцев у волка
    int ageParent; //возраст родителя
    bool readyToEat; //может ли гиена кушать
public:
    Hyena() : countAte(0), Animal(0, 0, 0, 0), ageParent(-1), readyToEat(1) {}
    Hyena(int x, int y, int d, int k, int age) : countAte(0), Animal(x, y, d, k), ageParent(age), readyToEat(1) {}
    ~Hyena() {}
    void setAte(int c)
    {
        this->countAte = c;
    }
    int getAte()
    {
        return countAte;
    }
    int getAgeParent()
    {
        return ageParent;
    }
    bool getReady()
    {
        return readyToEat;
    }
    void setReady()
    {
        this->readyToEat = 0;
    }
    void move(int height, int width)
    {
        switch (d)
        {
        case 0:
            switch (y)
            {
            case 0:
                y = height - 2;
                break;
            case 1:
                y = height - 1;
                break;
            default:
                y -= 2;
                break;
            }
            break;
        case 1:
            if (x == (width - 2))
            {
                x = 0;
            }
            else
            {
                if (x == (width - 1))
                {
                    x = 1;
                }
                else
                {
                    x += 2;
                }
            }
            break;
        case 2:
            if (y == (height - 2))
            {
                y = 0;
            }
            else
            {
                if (y == (height - 1))
                {
                    y = 1;
                }
                else
                {
                    y += 2;
                }
            }
            break;
        case 3:
            switch (x)
            {
            case 0:
                x = width - 2;
                break;
            case 1:
                x = width - 1;
                break;
            default:
                x -= 2;
                break;
            }
            break;
        }//switch
        now--;
        if (now == 0)
        {
            d++;
            if (d == 4)
            {
                d = 0;
            }
            now = k;
        }

    }
};
class Rabbit : public Animal
{
public:
    Rabbit() : Animal(0, 0, 0, 0) {}
    Rabbit(int x, int y, int d, int k) : Animal(x, y, d, k) {}
    ~Rabbit() {}
    void move(int height, int width)
    {
        switch (d)
        {
        case 0:
            if (y == 0)
            {
                y = height - 1;
            }
            else
            {
                y -= 1;
            }
            break;
        case 1:
            if (x == (width - 1))
            {
                x = 0;
            }
            else
            {
                x += 1;
            }
            break;
        case 2:
            if (y == (height - 1))
            {
                y = 0;
            }
            else
            {
                y += 1;
            }
            break;
        case 3:
            if (x == 0)
            {
                x = width - 1;
            }
            else
            {
                x -= 1;
            }
            break;
        }//switch
        now--;
        if(now == 0)
        {
            d++;
            if (d == 4)
            {
                d = 0;
            }
            now = k;
        }

    }
};
class Simulation
{
private:
    int height, width; //размеры поля
    int t; //количество шагов симуляции
    int countRab; //количество зайцев
    int countWolf; //количество волков
    int countHyena; //количество гиен
    int** field; //поле
    vector<Rabbit*> rabbit; //массив зайцев
    vector<Wolf*> wolf; //массив волков
    vector<Hyena*> hyena; //массив гиен
public:
    Simulation() : height(0), width(0), t(0), countRab(0), countWolf(0) {}
    Simulation(int n, int m, int t, int r, int w, int h, vector<Rabbit*> &rabbit, vector<Wolf*> &wolf, vector<Hyena*> &hyena) : height(n), width(m), t(t), countRab(r), countWolf(w), countHyena(h)
    {
        field = new int* [height];
        for (int i = 0; i < height; i++)
        {
            field[i] = new int[width];
            for (int j = 0; j < width; j++)
            {
                field[i][j] = 0;
            }
        }
        this->rabbit = rabbit;
        this->wolf = wolf;
        this->hyena = hyena;
    }
    Simulation(int n, int m, int t, int r, int w, vector<Rabbit*>& rabbit, vector<Wolf*>& wolf) : height(n), width(m), t(t), countRab(r), countWolf(w), countHyena(0)
    {
        field = new int* [height];
        for (int i = 0; i < height; i++)
        {
            field[i] = new int[width];
            for (int j = 0; j < width; j++)
            {
                field[i][j] = 0;
            }
        }
        this->rabbit = rabbit;
        this->wolf = wolf;
    }
    ~Simulation() 
    {
        for (int i = 0; i < height; i++)
        {
            delete[] field[i];
        }
        delete[] field;
    }
    void getStarted()
    {
        for (int i = 0; i < t; i++) //цикл по шагам симуляции
        {
            for (int j = 0; j < countRab; j++) //ходят зайцы
            {
                rabbit[j]->move(height, width);
                rabbit[j]->setAge(rabbit[j]->getAge() + 1);
            }
            for (int j = 0; j < countWolf; j++) //ходят волки
            {
                wolf[j]->move(height, width);
                wolf[j]->setAge(wolf[j]->getAge() + 1);
            }
            for (int j = 0; j < countHyena; j++) //ходят гиены
            {
                hyena[j]->move(height, width);
                hyena[j]->setAge(hyena[j]->getAge() + 1);
            }
            
            for (int i1 = 0; i1 < countHyena; i1++) //питание гиен зайцами
            {
                for (int j = 0; j < countRab; j++)
                {
                    if (!hyena[i1]->getReady())
                    {
                        break;
                    }
                    if ((hyena[i1]->getx() == rabbit[j]->getx()) && (hyena[i1]->gety() == rabbit[j]->gety()) && (hyena[i1]->getReady()))
                    {
                        int* hyenas = new int[countHyena];//массив с индексами гиен в одной клетке с зайцем
                        int kh = 0;
                        for (int ij = 0; ij < countHyena; ij++)
                        {
                            hyenas[ij] = 0;
                        }
                        int* rabits = new int[countRab];//массив с индексами зайцев в одной клетке с гиеной
                        int kr = 0;
                        for (int ij = 0; ij < countRab; ij++)
                        {
                            rabits[ij] = 0;
                        }
                        hyenas[kh] = i1; 
                        kh++; //количество гиен
                        rabits[kr] = j;
                        kr++; //количество зайцев
                        for (int ij = (i1 + 1); ij < countHyena; ij++) //ищем всех гиен на клетке с зайцем
                        {
                            if ((hyena[i1]->getx() == hyena[ij]->getx()) && (hyena[i1]->gety() == hyena[ij]->gety()) && (hyena[ij]->getReady()))
                            {
                                hyenas[kh] = ij;
                                kh++;
                            }
                        }
                        for (int ij = (j + 1); ij < countRab; ij++) //ищем всех зайцев на клетке с гиеной
                        {
                            if ((rabbit[j]->getx() == rabbit[ij]->getx()) && (rabbit[j]->gety() == rabbit[ij]->gety()))
                            {
                                rabits[kr] = ij;
                                kr++;
                            }
                        }
                        int nomOld = hyenas[0];
                        for (int ij = 1; ij < kh; ij++) //ищем самую старую гиену
                        {
                            if (t == 0)
                            {
                                break;
                            }
                            if (hyena[hyenas[ij]]->getAge() > hyena[hyenas[ij - 1]]->getAge())
                            {
                                nomOld = hyenas[ij];
                                continue;
                            }
                            if (hyena[hyenas[ij]]->getAge() == hyena[hyenas[ij - 1]]->getAge())
                            {
                                if (hyena[hyenas[ij]]->getAgeParent() > hyena[hyenas[ij - 1]]->getAgeParent())
                                {
                                    nomOld = hyenas[ij];
                                    continue;
                                }
                                if (hyena[hyenas[ij]]->getAgeParent() == hyena[hyenas[ij - 1]]->getAgeParent())
                                {
                                    nomOld = hyenas[ij - 1];
                                    continue;
                                }
                            }
                        }

                        while ((hyena[nomOld]->getReady()) && (countRab > 0) && (kr > 0))
                        {
                            int nomRab = rabits[0];
                            for (int ij = 1; ij < kr; ij++)
                            {
                                if (rabbit[rabits[ij]]->getAge() > rabbit[rabits[ij - 1]]->getAge())
                                {
                                    nomRab = rabits[ij];
                                }
                            }
                            hyena[nomOld]->setAte(hyena[nomOld]->getAte() + 1);
                            rabbit.erase(rabbit.begin() + nomRab);
                            countRab--;
                            kr--;
                            if (hyena[nomOld]->getAte() == 2)//если гиена съела двоих то перестает кушать других
                            {
                                hyena[nomOld]->setReady();
                                hyena.resize(countHyena + 1);
                                hyena[countHyena] = new Hyena(hyena[nomOld]->getx(), hyena[nomOld]->gety(), hyena[nomOld]->getd(), hyena[nomOld]->getk(), hyena[nomOld]->getAge());
                                countHyena++;
                            }
                        }
                        delete[] hyenas;
                        delete[] rabits;
                        
                    }
                }
            }

            for (int i1 = 0; i1 < countHyena; i1++) //питание гиен волками
            {
                for (int j = 0; j < countWolf; j++)
                {
                    if (!hyena[i1]->getReady())
                    {
                        break;
                    }
                    if ((hyena[i1]->getx() == wolf[j]->getx()) && (hyena[i1]->gety() == wolf[j]->gety()) && (hyena[i1]->getReady()))
                    {
                        int* hyenas = new int[countHyena];//массив с индексами гиен в одной клетке с волком
                        int kh = 0;
                        for (int ij = 0; ij < countHyena; ij++)
                        {
                            hyenas[ij] = 0;
                        }
                        int* wolfs = new int[countWolf];//массив с индексами волков в одной клетке с гиеной
                        int kw = 0;
                        for (int ij = 0; ij < countWolf; ij++)
                        {
                            wolfs[ij] = 0;
                        }
                        hyenas[kh] = i1;
                        kh++; //количество гиен
                        wolfs[kw] = j;
                        kw++; //количество волков
                        for (int ij = (i1 + 1); ij < countHyena; ij++) //ищем всех гиен на клетке с волком
                        {
                            if ((hyena[i1]->getx() == hyena[ij]->getx()) && (hyena[i1]->gety() == hyena[ij]->gety()) && (hyena[ij]->getReady()))
                            {
                                hyenas[kh] = ij;
                                kh++;
                            }
                        }
                        for (int ij = (j + 1); ij < countWolf; ij++) //ищем всех волков на клетке с гиеной
                        {
                            if ((wolf[j]->getx() == wolf[ij]->getx()) && (wolf[j]->gety() == wolf[ij]->gety()))
                            {
                                wolfs[kw] = ij;
                                kw++;
                            }
                        }
                        int nomOld = hyenas[0];
                        for (int ij = 1; ij < kh; ij++) //ищем самую старую гиену
                        {
                            if (t == 0)
                            {
                                break;
                            }
                            if (hyena[hyenas[ij]]->getAge() > hyena[hyenas[ij - 1]]->getAge())
                            {
                                nomOld = hyenas[ij];
                                continue;
                            }
                            if (hyena[hyenas[ij]]->getAge() == hyena[hyenas[ij - 1]]->getAge())
                            {
                                if (hyena[hyenas[ij]]->getAgeParent() > hyena[hyenas[ij - 1]]->getAgeParent())
                                {
                                    nomOld = hyenas[ij];
                                    continue;
                                }
                                if (hyena[hyenas[ij]]->getAgeParent() == hyena[hyenas[ij - 1]]->getAgeParent())
                                {
                                    nomOld = hyenas[ij - 1];
                                    continue;
                                }
                            }
                        }

                        while ((hyena[nomOld]->getReady()) && (countWolf > 0) && (kw > 0))
                        {
                            int nomWof = wolfs[0];
                            for (int ij = 1; ij < kw; ij++)
                            {
                                if (wolf[wolfs[ij]]->getAge() > wolf[wolfs[ij - 1]]->getAge())
                                {
                                    nomWof = wolfs[ij];
                                }
                            }
                            hyena[nomOld]->setAte(hyena[nomOld]->getAte() + 1);
                            wolf.erase(wolf.begin() + nomWof);
                            countWolf--;
                            kw--;
                            if (hyena[nomOld]->getAte() == 2)//если гиена съела двоих то перестает кушать других
                            {
                                hyena[nomOld]->setReady();
                                hyena.resize(countHyena + 1);
                                hyena[countHyena] = new Hyena(hyena[nomOld]->getx(), hyena[nomOld]->gety(), hyena[nomOld]->getd(), hyena[nomOld]->getk(), hyena[nomOld]->getAge());
                                countHyena++;
                            }
                        }
                        delete[] hyenas;
                        delete[] wolfs;
                    }
                }
            }

            for (int i1 = 0; i1 < countHyena; i1++) //питание гиен гиенами
            {
                for (int j = (i1 + 1); j < countHyena; j++)
                {
                    if (!hyena[i1]->getReady())
                    {
                        break;
                    }
                    if ((hyena[i1]->getx() == hyena[j]->getx()) && (hyena[i1]->gety() == hyena[j]->gety()) && (hyena[i1]->getReady()))
                    {
                        int* hyenas = new int[countHyena];//массив с индексами гиен в одной клетке с гиеной-жертвой
                        int kh = 0;
                        for (int ij = 0; ij < countHyena; ij++)
                        {
                            hyenas[ij] = 0;
                        }
                        int* hyenass = new int[countHyena];//массив с индексами жертв гиен в одной клетке с гиеной
                        int kh1 = 0;
                        for (int ij = 0; ij < countHyena; ij++)
                        {
                            hyenass[ij] = 0;
                        }
                        hyenas[kh] = i1;
                        kh++; //количество гиен
                        hyenass[kh1] = j;
                        kh1++; //количество жертв гиен
                        for (int ij = (i1 + 1); ij < countHyena; ij++) //ищем всех гиен на клетке с гиеной-жертвой
                        {
                            if ((hyena[i1]->getx() == hyena[ij]->getx()) && (hyena[i1]->gety() == hyena[ij]->gety()) && (hyena[ij]->getReady()))
                            {
                                hyenas[kh] = ij;
                                kh++;
                            }
                        }
                        for (int ij = (j + 1); ij < countHyena; ij++) //ищем всех гиен-жертв на клетке с гиеной
                        {
                            if ((hyena[j]->getx() == hyena[ij]->getx()) && (hyena[j]->gety() == hyena[ij]->gety()))
                            {
                                hyenass[kh1] = ij;
                                kh1++;
                            }
                        }
                        int nomOld = hyenas[0];
                        for (int ij = 1; ij < kh; ij++) //ищем самую старую гиену
                        {
                            if (t == 0)
                            {
                                break;
                            }
                            if (hyena[hyenas[ij]]->getAge() > hyena[hyenas[ij - 1]]->getAge())
                            {
                                nomOld = hyenas[ij];
                                continue;
                            }
                            if (hyena[hyenas[ij]]->getAge() == hyena[hyenas[ij - 1]]->getAge())
                            {
                                if (hyena[hyenas[ij]]->getAgeParent() > hyena[hyenas[ij - 1]]->getAgeParent())
                                {
                                    nomOld = hyenas[ij];
                                    continue;
                                }
                                if (hyena[hyenas[ij]]->getAgeParent() == hyena[hyenas[ij - 1]]->getAgeParent())
                                {
                                    nomOld = hyenas[ij - 1];
                                    continue;
                                }
                            }
                        }

                        while ((hyena[nomOld]->getReady()) && (countHyena > 0) && (kh1 > 0))
                        {
                            int nomH = hyenass[0];
                            for (int ij = 1; ij < kh1; ij++)
                            {
                                if (hyena[hyenass[ij]]->getAge() > hyena[hyenass[ij - 1]]->getAge())
                                {
                                    nomH = hyenass[ij];
                                }
                            }
                            hyena[nomOld]->setAte(hyena[nomOld]->getAte() + 1);
                            hyena.erase(hyena.begin() + nomH);
                            countHyena--;
                            kh1--;
                            if (hyena[nomOld]->getAte() == 2)//если гиена съела двоих то перестает кушать других
                            {
                                hyena[nomOld]->setReady();
                                hyena.resize(countHyena + 1);
                                hyena[countHyena] = new Hyena(hyena[nomOld]->getx(), hyena[nomOld]->gety(), hyena[nomOld]->getd(), hyena[nomOld]->getk(), hyena[nomOld]->getAge());
                                countHyena++;
                            }
                        }
                        delete[] hyenas;
                        delete[] hyenass;
                    }
                }
            }

            for (int i1 = 0; i1 < countWolf; i1++) //процесс питания волков
            {
                for (int j = 0; j < countRab; j++)
                {
                    if ((wolf[i1]->getx() == rabbit[j]->getx()) && (wolf[i1]->gety() == rabbit[j]->gety()))
                    {
                        int* wolfes = new int[countWolf];
                        int kw = 0;
                        for (int ij = 0; ij < countWolf; ij++)
                        {
                            wolfes[ij] = 0;
                        }
                        int* rabits = new int[countRab];
                        int kr = 0;
                        for (int ij = 0; ij < countRab; ij++)
                        {
                            rabits[ij] = 0;
                        }
                        wolfes[kw] = i1;
                        kw++;
                        rabits[kr] = j;
                        kr++;
                        for (int ij = (i1 + 1); ij < countWolf; ij++) //ищем всех волков на клетке с зайцем
                        {
                            if ((wolf[i1]->getx() == wolf[ij]->getx()) && (wolf[i1]->gety() == wolf[ij]->gety()))
                            {
                                wolfes[kw] = ij;
                                kw++;
                            }
                        }
                        for (int ij = (j + 1); ij < countRab; ij++) //ищем всех зайцев на клетке с волком
                        {
                            if ((rabbit[j]->getx() == rabbit[ij]->getx()) && (rabbit[j]->gety() == rabbit[ij]->gety()))
                            {
                                rabits[kr] = ij;
                                kr++;
                            }
                        }
                        int nomOld = wolfes[0];
                        for (int ij = 1; ij < kw; ij++) //ищем самого старого волка
                        {
                            if (t == 0)
                            {
                                break;
                            }
                            if (wolf[wolfes[ij]]->getAge() > wolf[wolfes[ij - 1]]->getAge())
                            {
                                nomOld = wolfes[ij];
                                continue;
                            }
                            if (wolf[wolfes[ij]]->getAge() == wolf[wolfes[ij - 1]]->getAge())
                            {
                                if (wolf[wolfes[ij]]->getAgeParent() > wolf[wolfes[ij - 1]]->getAgeParent())
                                {
                                    nomOld = wolfes[ij];
                                    continue;
                                }
                                if (wolf[wolfes[ij]]->getAgeParent() == wolf[wolfes[ij - 1]]->getAgeParent())
                                {
                                    nomOld = wolfes[ij - 1];
                                    continue;
                                }
                            }    
                        }
                        wolf[nomOld]->setRab(wolf[nomOld]->getAteRab() + kr);//добавляем к счетчику съеденного зайца/ев
                        for (int ij = 0; ij < kr; ij++) //удаление съеденных зайцев
                        {
                            rabbit.erase(rabbit.begin() + rabits[ij]);
                            countRab--;
                        }
                        if (wolf[nomOld]->getAteRab() >= 2) //рождение волчонка
                        {
                            wolf[nomOld]->setRab(0);
                            wolf.resize(countWolf + 1);
                            wolf[countWolf] = new Wolf(wolf[nomOld]->getx(), wolf[nomOld]->gety(), wolf[nomOld]->getd(), wolf[nomOld]->getk(), wolf[nomOld]->getAge());
                            countWolf++;
                        }
                        delete[] wolfes;
                        delete[] rabits;
                    }
                }
            }//for питание
            for (int j = 0; j < countRab; j++) //размножение и смерть зайцев
            {
                if (rabbit[j]->getAge() == 5)
                {
                    rabbit.resize(countRab + 1);
                    rabbit[countRab] = new Rabbit(rabbit[j]->getx(), rabbit[j]->gety(), rabbit[j]->getd(), rabbit[j]->getk());
                    countRab++;
                    
                }
                if (rabbit[j]->getAge() == 10)
                {
                    rabbit.resize(countRab + 1);
                    rabbit[countRab] = new Rabbit(rabbit[j]->getx(), rabbit[j]->gety(), rabbit[j]->getd(), rabbit[j]->getk());
                    rabbit.erase(rabbit.begin() + j);
                    j = -1;
                }
            }
            for (int j = 0; j < countWolf; j++) //смерть волка
            {
                if (wolf[j]->getAge() == 15)
                {
                    wolf.erase(wolf.begin() + j);
                    countWolf--;
                }
            }
            for (int j = 0; j < countHyena; j++) //смерть гиены
            {
                if (hyena[j]->getAge() == 15)
                {
                    hyena.erase(hyena.begin() + j);
                    countHyena--;
                }
            }
            //print();
            //system("pause");
        }
    }
    void print()
    {
        //system("cls");
        for (int i = 0; i < countRab; i++)
        {
            field[rabbit[i]->gety()][rabbit[i]->getx()]++;
        }
        for (int i = 0; i < countWolf; i++)
        {
            field[wolf[i]->gety()][wolf[i]->getx()]--;
        }
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (field[i][j] == 0)
                {
                    out << "#";
                }
                else
                {
                    out << field[i][j];
                }
                field[i][j] = 0;
            }
            out << endl;
        }
        
        
    }
};

int main()
{
    int n = 0, m = 0, t = 0;
    in >> n >> m >> t; //размеры поля и количество ходов
    int r = 0, w = 0, h = 0;
    in >> r >> w;
    //in >> r >> w >> h; //количество зайцев, волков и гиен
    int x = 0, y = 0, d = 0, k = 0;

    vector<Rabbit*> rabbits(r);
    for (int i = 0; i < r; i++)
    {
        in >> x >> y >> d >> k; //x,y - координаты зайца, d - направление движения, k - постоянство зайца
        rabbits[i] = new Rabbit(x, y, d, k);
    }
    vector<Wolf*> wolf(w);
    for (int i = 0; i < w; i++)
    {
        in >> x >> y >> d >> k; //x,y - координаты волка, d - направление движения, k - постоянство волка
        wolf[i] = new Wolf(x, y, d, k, -1);
    }
    //vector<Hyena*> hyena(h);
    //for (int i = 0; i < h; i++)
    //{
    //    in >> x >> y >> d >> k; //x,y - координаты волка, d - направление движения, k - постоянство волка
    //    hyena[i] = new Hyena(x, y, d, k, -1);
    //}

    Simulation a(n, m, t, r, w, rabbits, wolf);
    //Simulation a(n, m, t, r, w, h, rabbits, wolf, hyena);

    //a.print();
    //system("pause");
    a.getStarted();
    a.print();
    rabbits.clear();
    wolf.clear();
    //hyena.clear();
    return 0;
}

