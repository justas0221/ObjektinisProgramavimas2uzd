#include "funkcijos.h"
#include "strukturos.h"

int main()
{
    vector<studentas> stud; // Studentu strukturu vektorius
    string skaiciavimoBudas, eilute; // Kintamasis, kuriame saugomas vartotojo pasirinkimas, kaip skaiciuoti galutini bala, naudojant vidurki ar mediana
    int tarpai;
    bool teisingasIvedimas;
    int i = 0, j, parinktis, studentuKiekis, k, l, papildymas, isvedimasFaile, rikiavimas;
    char testiPrograma;
    ifstream input;

    srand(time(0));

    do // Prasome studento ivesti skaiciu, nuo kurio priklausys, kaip bus vykdoma programa
    {
        try
        {
            cout << "Pasirinkite, kaip norite vykdyti programa\n1 - Viska vesti ranka\n2 - Generuoti pazymius atsitiktinai\n3 - Generuoti pazymius ir studentu vardus, pavardes atsitiktinai\n4 - Baigti darba\n5 - Skaityti duomenis is failo\n"; 
            
            if (!(cin >> parinktis))
            {
                throw runtime_error("Klaidingi duomenys. Iveskite kazkuri is skaiciu nuo 1 iki 5 imtinai.");
            }

            teisingasIvedimas = (parinktis >= 1 && parinktis <= 5 && cin.peek() == '\n');

            if (!teisingasIvedimas)
            {
                throw runtime_error("Klaidingi duomenys. Iveskite kazkuri is skaiciu nuo 1 iki 5 imtinai.");
            }
        }
        catch (const exception& e)
        {
            cerr << "Klaida: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    } while (!teisingasIvedimas);

    if (parinktis == 4)
    {
        exit(0);
    }

    if (parinktis != 5) // Prasome ivesti pradini studentu kieki
    {
        do
        {
            try
            {
                cout << "Iveskite studentu kieki (nuo 1 iki 10 imtinai): ";

                if (!(cin >> studentuKiekis))
                {
                    throw runtime_error("Klaidingi duomenys. Iveskite sveikaji skaiciu nuo 1 iki 10 imtinai.");
                }

                teisingasIvedimas = (studentuKiekis >= 1 && studentuKiekis <= 10 && cin.peek() == '\n');

                if (!teisingasIvedimas)
                {
                    throw runtime_error("Klaidingi duomenys. Iveskite sveikaji skaiciu nuo 1 iki 10 imtinai.");
                }
            }
            catch (const exception& e)
            {
                cerr << "Klaida: " << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        } while (!teisingasIvedimas);
    
    }

    if (parinktis == 5) // Jei vartotojas nori nuskaityti duomenis is failo, atidarome duomenu faila ir praleidziame pirmaja eilute, kuri yra antrastine
    {
        input.open("studentai10000.txt");
        try
        {
            if (!input)
            {
                throw runtime_error("Failas neegzistuoja.");
            }
        }
        catch(const exception& e)
        {
            cerr << "Klaida: " << e.what() << endl;
            exit(1);
        }
    }

    do
    {
        try
        {
            cout << "Ka norite naudoti galutinio balo skaiciavimui, pazymiu vidurki ar mediana? (Irasykite \'V\' arba \'M\') "; // Vartotojo prasome ivesti vidurkio skaiciavimo buda tol, kol jis ives reikiama simboli

            if (!(cin >> skaiciavimoBudas))
            {
                throw runtime_error("Klaidingi duomenys. Iveskite V arba M.");
            }

            skaiciavimoBudas = didziosios(skaiciavimoBudas); // Ivestos raides pakeiciamos i didziasias, kad reiktu maziau tikrinti

            teisingasIvedimas = ((skaiciavimoBudas == "V" || skaiciavimoBudas == "M") && cin.peek() == '\n');

            if (!teisingasIvedimas) // Tikriname, ar vartotojas ivede viena is dvieju galimu ivesti raidziu be jokiu papildomu simboliu, jei ne, tuomet pranesame vartotojui apie klaida
            {
                throw runtime_error("Klaidingi duomenys. Iveskite V arba M.");
            }
        }
        catch(const exception& e)
        {
            cerr << "Klaida: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    } while (!teisingasIvedimas);

    do // Klausiame vartotojo, kokia tvarka jis nori isrikiuoti studentus rezultatuose
    {
        try
        {
            cout << "Jei norite studentus isrikiuoti pagal galutini bala mazejimo tvarka, iveskite \"1\", jei didejimo, iveskite \"0\": ";

            if (!(cin >> rikiavimas) && (rikiavimas != 1 || rikiavimas != 0 || cin.peek() != '\n'))
            {
                throw runtime_error("Klaidingi duomenys. Iveskite \"1\" arba \"0\".");
            }

            teisingasIvedimas = ((rikiavimas == 1 || rikiavimas == 0) && cin.peek() == '\n');

            if (!teisingasIvedimas)
            {
                throw runtime_error("Klaidingi duomenys. Iveskite \"1\" arba \"0\".");
            }
        }
        catch(const exception& e)
        {
            cerr << "Klaida: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    } while (!teisingasIvedimas);

    do // Klausiame vartotojo, ar jis nori rezultatus irasyti i faila, ar isvesti i ekrana
    {
        try
        {
            cout << "Jei norite rezultatus irasyti i faila, iveskite \"1\", jei norite isvesti juos i ekrana, iveskite \"0\": ";

            if (!(cin >> isvedimasFaile) && (isvedimasFaile != 1 || isvedimasFaile != 0 || cin.peek() != '\n'))
            {
                throw runtime_error("Klaidingi duomenys. Iveskite \"1\" arba \"0\".");
            }

            teisingasIvedimas = ((isvedimasFaile == 1 || isvedimasFaile == 0) && cin.peek() == '\n');

            if (!teisingasIvedimas)
            {
                throw runtime_error("Klaidingi duomenys. Iveskite \"1\" arba \"0\".");
            }
        }
        catch(const exception& e)
        {
            cerr << "Klaida: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    } while (!teisingasIvedimas);

    auto start = chrono::high_resolution_clock::now(); // Pradedame programos veikimo laikmati

    l = 0;
    papildymas = 0;

    while (true)
    {
        studentuKiekis += papildymas;
        studentas naujasStudentas;

        if (parinktis != 5)
        {
            for (int i = l; i < studentuKiekis; i++)
            {
                int randomPazymiuKiekis = rand() % 10 + 1;
                int pazymiuKiekis = 0;
                
                if (parinktis == 1 || parinktis == 2)
                {
                    do
                    {
                        try
                        {
                            cout << "Iveskite studento varda: "; // Prasome vartotojo ivesti kiekvieno studento varda tol, kol tas vardas yra vienas zodis, sudarytas tik is raidziu
                            
                            if (!(cin >> naujasStudentas.vardas))
                            {
                                throw runtime_error("Klaidingi duomenys. Vardas turi buti vienas zodis, sudarytas tik is raidziu (jei studentas turi du vardus, iveskite tik viena is ju).");
                            }

                            tarpai = tarpuSkaicius(naujasStudentas.vardas); // Randame ivesties tarpu skaiciu

                            teisingasIvedimas = (tarpai == 0 && tikRaides(naujasStudentas.vardas) && cin.peek() == '\n');

                            if (!teisingasIvedimas) // Jei tarpu skaicius nera nulis arba vardas sudarytas ne tik is raidziu, arba sekantis po zodzio esantis simbolis nera naujos eilutes simbolis, pranesame apie klaida, laikome ivedima neteisingu
                            {
                                throw runtime_error("Klaidingi duomenys. Vardas turi buti vienas zodis, sudarytas tik is raidziu (jei studentas turi du vardus, iveskite tik viena is ju).");
                            }
                        }
                        catch(const exception& e)
                        {
                            cerr << "Klaida: " << e.what() << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                        }
                    } while (!teisingasIvedimas); // Vykdome cikla kol ivedimas neteisingas
                    do
                    {
                        try
                        {
                            cout << "Iveskite studento pavarde: "; // Prasome vartotojo ivesti kiekvieno studento pavarde tol, kol ta pavarde yra vienas zodis, sudarytas tik is raidziu
                            
                            if (!(cin >> naujasStudentas.pavarde))
                            {
                                throw runtime_error("Klaidingi duomenys. Pavarde turi buti vienas zodis, sudarytas tik is raidziu.");
                            }

                            tarpai = tarpuSkaicius(naujasStudentas.pavarde); // Randame ivesties tarpu skaiciu

                            teisingasIvedimas = (tarpai == 0 && tikRaides(naujasStudentas.pavarde) && cin.peek() == '\n');

                            if (!teisingasIvedimas) // Jei tarpu skaicius nera nulis arba vardas sudarytas ne tik is raidziu, arba sekantis po zodzio esantis simbolis nera naujos eilutes simbolis, pranesame apie klaida, laikome ivedima neteisingu
                            {
                                throw runtime_error("Klaidingi duomenys. Pavarde turi buti vienas zodis, sudarytas tik is raidziu.");
                            }
                        }
                        catch(const exception& e)
                        {
                            cerr << "Klaida: " << e.what() << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                        }
                    } while (!teisingasIvedimas); // Vykdome cikla kol ivedimas neteisingas

                    naujasStudentas.vardas = didziosios(naujasStudentas.vardas); // Kiekviena vardo raide paverciama didziaja, kad atrodytu tvarkingiau isvedant duomenis
                            
                    naujasStudentas.pavarde = didziosios(naujasStudentas.pavarde); // Kiekviena pavardes raide paverciama didziaja, kad atrodytu tvarkingiau isvedant duomenis
                }

                if (parinktis == 1)
                {
                    do
                    {
                        try
                        {
                            cout << "Kiek pazymiu norite ivesti siam studentui? (Irasykite skaiciu nuo 1 iki 10 imtinai): ";

                            if (!(cin >> pazymiuKiekis))
                            {
                                throw runtime_error("Klaidingi duomenys. Iveskite skaiciu nuo 1 iki 10 imtinai.");
                            }

                            teisingasIvedimas = (pazymiuKiekis >= 1 && pazymiuKiekis <= 10 && cin.peek() == '\n');

                            if (!teisingasIvedimas)
                            {
                                throw runtime_error("Klaidingi duomenys. Iveskite skaiciu nuo 1 iki 10 imtinai.");
                            }
                        }
                        catch(const exception& e)
                        {
                            cerr << "Klaida: " << e.what() << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                        }
                    } while (!teisingasIvedimas);

                    k = 0;
                    papildymas = 0;
                    
                    while (true)
                    {
                        pazymiuKiekis += papildymas;

                        for (int j = k; j < pazymiuKiekis; j++)
                        {
                            string ivedimas;
                            
                            do
                            {
                                try
                                {
                                    cout << "Iveskite " << i + 1 << "-o studento " << j + 1 << "-aji pazymi: ";
            
                                    if (!(cin >> ivedimas))
                                    {
                                        throw runtime_error("Klaidingi duomenys. Prasome ivesti viena sveikaji skaiciu nuo 1 iki 10.");
                                    }

                                    teisingasIvedimas = ((ivedimas.size() == 1 || (ivedimas.size() == 2 && (ivedimas[0] == '1' && ivedimas[1] == '0'))) && cin.peek() == '\n' && isdigit(ivedimas[0]));

                                    if (!teisingasIvedimas) // Tikriname, ar vartotojo ivedima sudaro vienas arba du simboliai, jei ji sudaro du simboliai tikriname ar pirmas simbolis - vienetas, o antras - nulis, ir tikriname ar po pirmo skaiciaus iskart eina naujos eilutes simbolis
                                    {
                                        throw runtime_error("Klaidingi duomenys. Prasome ivesti viena sveikaji skaiciu nuo 1 iki 10.");
                                    }
                                    else
                                    {
                                        int pazymys = stoi(ivedimas); // Paverciame ivesta string'a i int'a
                                        if (pazymys < 1 || pazymys > 10) // Jei tas skaicius nera tarp 1 ir 10 imtinai, pranesame apie klaida
                                        {
                                            teisingasIvedimas = false;
                                            cout << "Klaidingi duomenys. Prasome ivesti viena sveikaji skaiciu nuo 1 iki 10." << endl;
                                        }
                                        else
                                        {
                                            naujasStudentas.nd.push_back(pazymys); // Jei skaicius yra tarp 1 ir 10 imtinai, priskiriame ji i atitinkamo studento pazymiu masyva
                                        }
                                    }
                                }
                                catch(const exception& e)
                                {
                                    cerr << "Klaida: " << e.what() << endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    continue;
                                }
                            } while (!teisingasIvedimas); // Vykdome cikla kol ivedimas yra neteisingas
                            
                            k = j + 1;
                        }

                        do
                        {
                            cout << "Jei norite daugiau pazymiu, iveskite papildomu pazymiu kieki (Irasykite skaiciu nuo 1 iki 10 imtinai), jei ne, iveskite bet koki simboli ir spauskite \"Enter\": "; // Klausiame, ar vartotojas nori prideti daugiau pazymiu i vektoriu
                            cin >> papildymas;

                            teisingasIvedimas = true;

                            if (papildymas == 0)
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                break;
                            }
                            else if (papildymas > 10 || papildymas < 1)
                            {
                                teisingasIvedimas = false;
                                cout << "Klaidingi duomenys. Iveskite skaiciu nuo 1 iki 10 imtinai." << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        } while (!teisingasIvedimas);

                        if (papildymas == 0)
                        {
                            break;
                        }
                    }

                    do
                    {
                        string ivedimas;

                        cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi: ";
                        cin >> ivedimas;
                                
                        teisingasIvedimas = true;

                        if (ivedimas.size() < 1 || (ivedimas.size() > 2 || (ivedimas.size() == 2 && (ivedimas[0] != '1' || ivedimas[1] != '0')) || cin.peek() != '\n') || !isdigit(ivedimas[0])) // Tikriname, ar vartotojo ivedima sudaro vienas arba du simboliai, jei ji sudaro du simboliai tikriname ar pirmas simbolis - vienetas, o antras - nulis, ir tikriname ar po pirmo skaiciaus iskart eina naujos eilutes simbolis
                            {
                                teisingasIvedimas = false; // Jei atsitinka taip, kad kazkuris is reikalavimu yra patenkinamas, tuomet pranesame apie klaida, isvalome klaidu flag'us ir ignoruojame likusia eilutes dali
                                cout << "Klaidingi duomenys. Prasome ivesti viena sveikaji skaiciu nuo 1 iki 10." << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            else
                            {
                                int pazymys = stoi(ivedimas); // Paverciame ivesta string'a i int'a
                                if (pazymys < 1 || pazymys > 10) // Jei tas skaicius nera tarp 1 ir 10 imtinai, pranesame apie klaida
                                {
                                    teisingasIvedimas = false;
                                    cout << "Klaidingi duomenys. Prasome ivesti viena sveikaji skaiciu nuo 1 iki 10." << endl;
                                }
                                else
                                {
                                    naujasStudentas.egz = pazymys; // Jei skaicius yra tarp 1 ir 10 imtinai, priskiriame ji kaip atitinkamo studento egzamino pazymi
                                }
                            }
                    } while (!teisingasIvedimas); // Vykdome cikla kol ivedimas yra neteisingas
                }

                if (parinktis == 2)
                {
                        for (int j = 0; j < randomPazymiuKiekis; j++)
                        {
                            int pazymys = generuotiPazymi();
                            
                            naujasStudentas.nd.push_back(pazymys); // Sugeneruota pazymi pridedame i vektoriu
                                
                            cout << "Sugeneruotas " << i + 1 << "-o studento " << j + 1 << "-aji pazymys: " << pazymys << endl;
                        }
                        
                        int pazymys = generuotiPazymi();

                        naujasStudentas.egz = pazymys;

                        cout << "Sugeneruotas " << i + 1 << "-o studento egzamino pazymys: " << pazymys << endl;
                }

                if (parinktis == 3)
                {
                        naujasStudentas.vardas = generuotiVarda(); // Sugeneruota varda priskiriame naujam studentui
                        naujasStudentas.pavarde = generuotiPavarde(); // Sugeneruota pavarde priskiriame naujam studentui

                        cout << "Sugeneruoti " << i + 1 << "-o studento vardas ir pavarde: " << naujasStudentas.vardas << " " << naujasStudentas.pavarde << endl;
                        for (int j = 0; j < randomPazymiuKiekis; j++)
                        {
                            int pazymys = generuotiPazymi();
                            
                            naujasStudentas.nd.push_back(pazymys); // Sugeneruota pazymi pridedame i vektoriu

                            cout << "Sugeneruotas " << i + 1 << "-o studento " << j + 1 << "-asis pazymys: " << pazymys << endl;
                        }
                        
                        int pazymys = generuotiPazymi();

                        naujasStudentas.egz = pazymys;

                        cout << "Sugeneruotas " << i + 1 << "-o studento egzamino pazymys: " << pazymys << endl;
                }

                stud.push_back(naujasStudentas);
                naujasStudentas.nd.clear();
                l = i + 1;
            }
    
            do
            {
                cout << "Jei norite daugiau studentu, iveskite papildomu studentu kieki (Irasykite skaiciu nuo 1 iki 10 imtinai), jei ne, iveskite bet koki simboli ir spauskite \"Enter\": "; // Klausiame, ar vartotojas nori prideti daugiau studentu i vektoriu
                cin >> papildymas;

                teisingasIvedimas = true;

                if (papildymas == 0)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                else if (papildymas > 10 || papildymas < 1)
                {
                    teisingasIvedimas = false;
                    cout << "Klaidingi duomenys. Iveskite skaiciu nuo 1 iki 10 imtinai." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (!teisingasIvedimas);

            if (papildymas == 0)
            {
                break;
            }
        }
        else
        {
            getline(input, eilute); // Praleidziame pirmaja failo eilute

            while (getline(input, eilute)) // Skaitome duomenis is failo kol ju yra
            {
                istringstream iss(eilute); // Padaliname juos i atskirus string'us, atskirtus tarpais
                string dalis;

                iss >> naujasStudentas.vardas >> naujasStudentas.pavarde;

                while (iss >> dalis)
                {
                    int pazymys = stoi(dalis); // Pazymi paverciame is string'o i int'a ir pridedame i naujo studento pazymiu vektoriu
                    naujasStudentas.nd.push_back(pazymys);
                }

                naujasStudentas.egz = naujasStudentas.nd.back();

                naujasStudentas.nd.pop_back();

                stud.push_back(naujasStudentas); // Nauja studenta pridedame i studentu vektoriaus gala
                naujasStudentas.nd.clear();
            }

        }
        if (parinktis == 5) // Jei vartotojas rinkosi nuskaityti duomenis is failo, cia nuskaitymas ir baigiasi, nes prideti studentu neimanoma
        {
            break;
        }
    }

    input.close(); // Uzdarome duomenu faila

    for (int i = 0; i < stud.size(); i++) // Skaiciuojame kiekvieno studento vidurki, mediana, o paskui ir galutinius balus 
    {
        stud[i].vidurkis = accumulate(stud[i].nd.begin(), stud[i].nd.end(), 0.0) / stud[i].nd.size();
        if (stud[i].nd.size() % 2 == 0)
        {
            stud[i].mediana = (stud[i].nd[stud[i].nd.size() / 2] + stud[i].nd[stud[i].nd.size() / 2 - 1]) / 2.0; // Jei pazymiu kiekis yra lyginis skaicius, mediana skaiciuojame rasdami dvieju viduriniu pazymiu aritmetini vidurki
        }
        else
        {
            stud[i].mediana = stud[i].nd[floor(stud[i].nd.size() / 2)]; // Jei pazymiu kiekis yra nelyginis skaicius, medianai priskiriame vidurini pazymi is pazymiu aibes
        }
        if (skaiciavimoBudas == "V")
        {
            stud[i].galutinis = 0.4 * stud[i].vidurkis + 0.6 * stud[i].egz; // Suskaiciuojame studento galutini bala, naudodami pazymiu vidurki
        }
        else
        {
            stud[i].galutinis = 0.4 * stud[i].mediana + 0.6 * stud[i].egz; // Suskaiciuojame studento galutini bala, naudodami pazymiu mediana
        }
    }

    if (rikiavimas == 1) // Priklausomai nuo to, kaip studentus isrikiuoti norejo vartotojas, iskvieciame tam skirtas funkcijas
    {
        sort(stud.begin(), stud.end(), palygintiDidejant);
    }
    else
    {
        sort(stud.begin(), stud.end(), palygintiMazejant);
    }
    
    if (isvedimasFaile)
    {
        ofstream output;
        output.open("output.txt");

        output << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl; // Tvarkingai isvedame antrastine eilute
        output << left << setw(80) << setfill('-') << "-" << endl; // Antrastinei eilutei atskirti naudojame is punktyrines linijos sudaryta antraja eilute
        output << setfill(' ');
        
        if (skaiciavimoBudas == "V")
        {    
            for(int i = 0; i < stud.size(); i++)
            {
                output << left << setw(20) << stud[i].vardas << setw(20) << stud[i].pavarde << setw(20) << fixed << setprecision(2) << stud[i].galutinis << setw(20) << "-.--" << endl; // Isvedame kiekvieno studento varda, pavarde ir galutini bala, priklausomai nuo skaiciavimo budo, kuri pasirinko vartotojas programos pradzioje
            }
        }
        else
        {
            for(int i = 0; i < stud.size(); i++)
            {
                output << left << setw(20) << stud[i].vardas << setw(20) << stud[i].pavarde << setw(20) << "-.--" << setw(20) << fixed << setprecision(2) << stud[i].galutinis << endl; // Isvedame kiekvieno studento varda, pavarde ir galutini bala, priklausomai nuo skaiciavimo budo, kuri pasirinko vartotojas programos pradzioje
            }
        }

        output.close();
    }
    else
    {
        cout << endl;
        cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl; // Tvarkingai isvedame antrastine eilute
        cout << left << setw(80) << setfill('-') << "-" << endl; // Antrastinei eilutei atskirti naudojame is punktyrines linijos sudaryta antraja eilute
        cout << setfill(' ');

        if (skaiciavimoBudas == "V")
        {    
            for(int i = 0; i < stud.size(); i++)
            {
                cout << left << setw(20) << stud[i].vardas << setw(20) << stud[i].pavarde << setw(20) << fixed << setprecision(2) << stud[i].galutinis << setw(20) << "-.--" << endl; // Isvedame kiekvieno studento varda, pavarde ir galutini bala, priklausomai nuo skaiciavimo budo, kuri pasirinko vartotojas programos pradzioje
            }
        }
        else
        {
            for(int i = 0; i < stud.size(); i++)
            {
                cout << left << setw(20) << stud[i].vardas << setw(20) << stud[i].pavarde << setw(20) << "-.--" << setw(20) << fixed << setprecision(2) << stud[i].galutinis << endl; // Isvedame kiekvieno studento varda, pavarde ir galutini bala, priklausomai nuo skaiciavimo budo, kuri pasirinko vartotojas programos pradzioje
            }
        }
    }

    auto end = chrono::high_resolution_clock::now(); // Sustabdome laikmati

    chrono::duration<double> duration = end - start; // Apskaiciuojame programos veikimo laika ir ji atspausdiname i ekrana

    cout << "Programos veikimo laikas sekundemis: " << duration.count() << endl;

    return 0;
}