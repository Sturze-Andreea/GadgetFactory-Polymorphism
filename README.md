# GadgetFactory-Polymorphism

Fabrica de gadget-uri

Operatorii unei fabrici de gadget-uri folosesc un soft pentru a gestiona seriile de dispozitive.
Operatorul are la dispozitie functionalitatile:
    1. Login. Dupa autentificarea cu success, sunt afisate toate seriile:
de tip Telefon(numeProducator, numeModel, unitatiProduse, listaOperatoriGSMCompatibili) si Drona(numeProducator, numeModel, unitatiProduse, numarRotoare)
Un producator poate avea mai multe serii chiar si pentru acelasi model.

    2. Operare (dupa autentificarea cu success)
           Cautare dupa numeProducator -> Se vor afisa toate informatiile seriilor acelui producator (indiferent de ce tip sunt)
           Adaugare. Operatorul poate introduce noi serii cu urmatorii validatori: unitatiProduse > 100 si un telefon trebuie sa aiba cel putin un operator in lista listaOperatoriGSMCompatibili;

    3. Logout
   
La pornirea aplicației utilizatorul poate alege tipul fișierului/fișierelor pe baza carora se vizualizeaza datele (CSV sau HTML
