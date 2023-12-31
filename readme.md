# Laborator POO - 2023/2024 - Tema 1
## Dima Florin-Alexandru - Grupa 262 - CTI, FMI Unibuc

Titlu: Gestiunea facturilor primite de la furnizori

Descriere: Tinerea unei evidente simple a facturilor

Motivatia alegerii temei: Pentru a pune in aplicare concepte de POO, am considerat relevanta alegerea unei teme practice, precum un program de tinerea evidentei facturilor. Scopul temei este cel de insusire a informatiilor legat de POO, deci nu am insistat pe tratarea erorilor din cauza inputului utilizatorului si am considerat ca ceea ce este introdus de la tastatura va fi adecvat pentru buna functionare a programului. De asemenea, nu am insistat asupra functionalitatilor (cum ar fi persistenta datelor intre mai multe sesiuni de utilizare) sau a amanuntelor legate de informatia stocata, ci am pastrat atentia asupra detaliilor de implementare a paradigmei de POO.

### Functiile aplicatiei:
0. Inchide aplicatia
1. Arata lista furnizori
2. Adauga furnizor - Trebuie introduse datele furnizorului: nume (identificator), iban
3. Arata lista facturi
4. Adauga factura - Trebuie introduse datele facturii: nume furnizor (trebuie sa existe furnizorul cu exact acelasi nume, case-sensitive!), valoarea facturii
5. Arata lista chitante
6. Adauga chitanta - Trebuie introduse datele chitantei: id factura, valoare platita
   In urma adaugarii unei chitante, valoarea ramasa de plata a facturii corespunzatoare este recalculata.

- Exista protectie impotriva optiunilor invalide.

### Clase
1. Aplicatie - Contine doar membri si metode statice, nu este permisa instantierea ei (este o clasa "statica"). Are rolul de a tine starea globala a aplicatiei (are lista de furnizori, facturi, chitante), de a gestiona navigatia si helper pentru gestionarea datelor.
2. Furnizor - Este de sine statator.
3. Factura - Trebuie sa aiba asociat un furnizor.
4. Chitanta - Trebuie sa aiba asociata o factura. In urma adaugarii unei chitante, valoarea ramasa a facturii asociate scade.

Pentru fiecare clasa, unde am observat utilitatea: constructor de initializare, constructor de copiere, operator de atribuire =, destructor, operator << suprascrise, am folosit "const".
