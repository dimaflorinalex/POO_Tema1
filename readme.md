# Laborator POO - 2023/2024 - Tema 1
## Dima Florin-Alexandru - Grupa 262 - CTI, FMI Unibuc

Titlu: Gestiunea facturilor primite de la furnizori

Descriere: Tinerea unei evidente simple a facturilor

### Functiile aplicatiei:
0. Inchide aplicatia
1. Arata lista furnizori
2. Adauga furnizor - Trebuie introduse datele furnizorului: nume (identificator), iban
3. Arata lista facturi
4. Adauga factura - Trebuie introduse datele facturii: nume furnizor, valoarea facturii
5. Arata lista chitante
6. Adauga chitanta - Trebuie introduse datele chitantei: id factura, valoare platita
   In urma adaugarii unei chitante, valoarea ramasa de plata a facturii corespunzatoare este recalculata.

- Exista protectie impotriva optiunilor invalide.

### Clase
Aplicatie - Contine doar membri si metode statice, nu este permisa instantierea ei (este o clasa "statica"). Are rolul de a tine starea globala a aplicatiei (are lista de furnizori, facturi, chitante), de a gestiona navigatia si helper pentru gestionarea datelor.
Furnizor - Este de sine statator.
Factura - Trebuie sa aiba asociat un furnizor.
Chitanta - Trebuie sa aiba asociata o factura. In urma adaugarii unei chitante, valoarea ramasa a facturii asociate scade.

Fiecare clasa are constructor de initializare, constructor de copiere, operator de atribuire, destructor suprascrise si am folosit "const" unde am observat utilitatea.
