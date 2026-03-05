CREATE DATABASE Cinematograf
GO
USE Cinematograf3
GO

CREATE TABLE Client
(cod_c INT PRIMARY KEY IDENTITY,
nume_client VARCHAR(100),
student VARCHAR(1))


--drop table Bilet
CREATE TABLE Bilet
(cod_b INT PRIMARY KEY IDENTITY,
pret INT,
reducere INT,
cod_c INT FOREIGN KEY REFERENCES Client(cod_c))

CREATE TABLE Cinema
(cod_cn INT PRIMARY KEY IDENTITY,
adresa VARCHAR(100))

CREATE TABLE Filme
(cod_f INT PRIMARY KEY IDENTITY,
titlu VARCHAR(50),
durata TIME,
limba VARCHAR(10))

CREATE TABLE CinemaFilme
(cod_cn INT FOREIGN KEY REFERENCES Cinema(cod_cn),
cod_f INT FOREIGN KEY REFERENCES Filme(cod_f)
CONSTRAINT pk_CinemaFilme PRIMARY KEY(cod_cn,cod_f))

CREATE TABLE Angajat
(cod_ang INT PRIMARY KEY IDENTITY,
nume_ang VARCHAR(50),
functie VARCHAR(50),
salariu INT,
cod_cn INT FOREIGN KEY REFERENCES Cinema(cod_cn))

CREATE TABLE Sala
(cod_sala INT PRIMARY KEY IDENTITY,
nr_locuri INT,
cod_cn INT FOREIGN KEY REFERENCES Cinema(cod_cn))

CREATE TABLE Loc
(cod_loc INT PRIMARY KEY IDENTITY,
rind INT,
numar INT,
cod_sala INT FOREIGN KEY REFERENCES Sala(cod_sala))

CREATE TABLE Proiectie
(cod_p INT PRIMARY KEY IDENTITY,
dt DATETIME,
cod_sala INT FOREIGN KEY REFERENCES Sala(cod_sala),
cod_f INT FOREIGN KEY REFERENCES Filme(cod_f))

CREATE TABLE Rezervare
(cod_r INT PRIMARY KEY IDENTITY,
cod_b INT FOREIGN KEY REFERENCES Bilet(cod_b),
cod_p INT FOREIGN KEY REFERENCES Proiectie(cod_p),
cod_loc INT FOREIGN KEY REFERENCES Loc(cod_loc),
status VARCHAR(10))

INSERT INTO Client (nume_client, student)
VALUES
('Popescu Andrei', 'Y'),
('Ionescu Maria', 'N'),
('Georgescu Vlad', 'Y'),
('Radu Elena', 'N'),
('Dumitrescu Mihai', 'Y');

INSERT INTO Client (nume_client, student)
VALUES
('Tudor Bianca', 'N'),
('Serban Luca', 'Y'),
('Cristea Oana', 'Y'),
('Pop Ana-Maria', 'N'),
('Filip Dan', 'Y');


INSERT INTO Bilet (pret, reducere, cod_c)
VALUES
(30, 0, 1),
(25, 5, 2),
(20, 10, 3),
(35, 0, 4),
(28, 5, 5);

INSERT INTO Bilet (pret, reducere, cod_c)
VALUES
(32, 0, 6),
(22, 10, 7),
(27, 5, 8),
(30, 0, 9),
(18, 15, 10);

INSERT INTO Cinema (adresa)
VALUES
('Str. Mihai Eminescu 10'),
('Bd. Carol I 45'),
('Str. Revolutiei 23'),
('Calea Victoriei 120'),
('Bd. Unirii 55');

INSERT INTO Cinema (adresa)
VALUES
('Str. Independentei 12'),
('Bd. Libertatii 89'),
('Str. Gh. Doja 33'),
('Calea Dorobanti 77'),
('Str. Academiei 14');

INSERT INTO Filme (titlu, durata, limba)
VALUES
('Inception', '02:28:00', 'EN'),
('Avatar', '02:42:00', 'EN'),
('Morometii', '01:55:00', 'RO'),
('Interstellar', '02:49:00', 'EN'),
('Everything Everywhere All At Once', '02:19:00', 'EN');

INSERT INTO Filme (titlu, durata, limba)
VALUES
('FNAF2', '02:49:00','EN')
INSERT INTO CinemaFilme (cod_cn, cod_f)
VALUES (1, 11)


INSERT INTO Filme (titlu, durata, limba)
VALUES
('The Matrix', '02:16:00', 'EN'),
('The Godfather', '02:55:00', 'EN'),
('La Vita e Bella', '01:56:00', 'IT'),
('Oppenheimer', '03:00:00', 'EN'),
('Dune', '02:35:00', 'EN')

INSERT INTO CinemaFilme (cod_cn, cod_f)
VALUES
(1, 1),
(1, 2),
(2, 3),
(3, 4),
(5, 5);

INSERT INTO CinemaFilme (cod_cn, cod_f)
VALUES
(6, 6),
(7, 7),
(8, 8),
(9, 9),
(10, 10);

INSERT INTO Angajat (nume_ang, functie, salariu, cod_cn)
VALUES
('Stan Ioana', 'Casier', 2800, 1),
('Munteanu Rares', 'Proiec?ionist', 3200, 1),
('Marin Ana', 'Manager', 4500, 2),
('Petrescu Radu', 'Tehnician', 3000, 3),
('Iliescu Dana', 'Casier', 2700, 5);

INSERT INTO Angajat (nume_ang, functie, salariu, cod_cn)
VALUES
('Gheorghe Miruna', 'Casier', 2600, 6),
('Radulescu Ion', 'Proiecționist', 3100, 7),
('Hristea Vlad', 'Manager', 4800, 8),
('Nistor Carmen', 'Tehnician', 2950, 9),
('Ursu Elena', 'Casier', 2750, 10);

INSERT INTO Sala (nr_locuri, cod_cn)
VALUES
(100, 1),
(80, 1),
(120, 2),
(90, 3),
(150, 5);

INSERT INTO Sala (nr_locuri, cod_cn)
VALUES
(110, 6),
(95, 7),
(130, 8),
(85, 9),
(140, 10);

INSERT INTO Loc (rind, numar, cod_sala)
VALUES
(1, 1, 1),
(1, 2, 1),
(2, 5, 2),
(3, 10, 3),
(4, 8, 5);

INSERT INTO Loc (rind, numar, cod_sala)
VALUES
(2, 3, 6),
(5, 12, 7),
(1, 7, 8),
(6, 9, 9),
(3, 4, 10);

INSERT INTO Proiectie (dt, cod_sala, cod_f)
VALUES
('2025-10-27 18:00:00', 1, 1),
('2025-10-27 20:30:00', 1, 2),
('2025-10-28 17:00:00', 2, 3),
('2025-10-28 21:00:00', 3, 4),
('2025-10-29 19:30:00', 5, 5);

INSERT INTO Proiectie (dt, cod_sala, cod_f)
VALUES
('2025-11-01 18:00:00', 6, 6),
('2025-11-01 21:00:00', 7, 7),
('2025-11-02 17:30:00', 8, 8),
('2025-11-02 20:00:00', 9, 9),
('2025-11-03 19:00:00', 10, 10);

INSERT INTO Rezervare (cod_b, cod_p, cod_loc, status)
VALUES
(1, 1, 1, 'valid'),
(2, 1, 2, 'valid'),
(3, 2, 3, 'anulat'),
(4, 4, 4, 'valid'),
(5, 5, 5, 'valid');

INSERT INTO Rezervare (cod_b, cod_p, cod_loc, status)
VALUES
(6, 6, 6, 'valid'),
(7, 7, 7, 'valid'),
(8, 8, 8, 'anulat'),
(9, 9, 9, 'valid'),
(10, 10, 10, 'valid');


--Afiseaza toti clientii care au bilete cu rezervari valide (status = valid) + codul biletului si statusul rezervarii
SELECT 
    c.nume_client AS Client,
    b.cod_b AS CodBilet,
    r.status AS StatusRezervare
FROM Client c, Bilet b, Rezervare r
WHERE c.cod_c = b.cod_c
  AND b.cod_b = r.cod_b
  AND r.status = 'valid';

--Afiseaza filmele care ruleaza in sali cu peste 100 de locuri impreuna cu numarul de locuri si data proiectiei
SELECT
    f.titlu AS Film,
    s.nr_locuri AS NumarLocuri,
    p.dt AS DataProiectiei
FROM Filme f, Proiectie p, Sala s
WHERE f.cod_f = p.cod_f
  AND p.cod_sala = s.cod_sala
  AND s.nr_locuri > 100;

--Afiseaza clientii care sunt studenti (student = 'Y') impreuna cu pretul si reducerea biletelor lor
SELECT
    c.nume_client AS Client,
    b.pret AS PretBilet,
    b.reducere AS Reducere
FROM Client c, Bilet b, Rezervare r
WHERE c.cod_c = b.cod_c
  AND b.cod_b = r.cod_b
  AND c.student = 'Y';

--filmele, clientii si pretul biletelor pentru biletele care costa<30
--relatie m-n -> Rezervare si Proiectie 
SELECT
    f.titlu AS Film,
    c.nume_client AS Client,
    b.pret AS Pret
FROM Filme f, Proiectie p, Rezervare r, Bilet b, Client c
WHERE f.cod_f = p.cod_f
  AND p.cod_p = r.cod_p
  AND r.cod_b = b.cod_b
  AND b.cod_c = c.cod_c
  AND b.pret < 30;

--Afiseaza adresele cinematografelor si numarul de locuri ale salilor
--Afiseaza pentru salile cu mai mult de 100 de locuri (fara repetitii).
SELECT DISTINCT
    cn.adresa AS AdresaCinema,
    s.nr_locuri AS NrLocuri
FROM Cinema cn, Sala s, Proiectie p
WHERE cn.cod_cn = s.cod_cn
  AND s.cod_sala = p.cod_sala
  AND s.nr_locuri > 100;

--Afiseaza filme cu titluri distincte si adresele distincte ale cinematografelor
-- relatie m-n filme cinema
SELECT DISTINCT
    f.titlu AS Film,
    cn.adresa AS Cinema
FROM Filme f, Cinema cn, CinemaFilme cf
WHERE f.cod_f = cf.cod_f
  AND cn.cod_cn = cf.cod_cn;

--calculeaza salariul mediu al angajatilor pentru fiecare cinematograf
--afisand adresa cinematografului si media salariilor.
SELECT
    cn.adresa AS AdresaCinema,
    AVG(a.salariu) AS SalariuMediu
FROM Cinema cn, Angajat a, Sala s
WHERE cn.cod_cn = a.cod_cn
  AND cn.cod_cn = s.cod_cn
GROUP BY cn.adresa;

--Afiseaza filmele care au mai mult de o proiectie
SELECT
    f.titlu AS Film,
    COUNT(p.cod_p) AS NumarProiectii
FROM Filme f, Proiectie p, Sala s
WHERE f.cod_f = p.cod_f
  AND p.cod_sala = s.cod_sala
GROUP BY f.titlu
HAVING COUNT(p.cod_p) > 1;

--- Afiseaza fiecare client si suma totala cheltuita pe bilete
---- doar pentru cei care au cheltuit mai mult de 50.
SELECT
    c.nume_client AS Client,
    SUM(b.pret - b.reducere) AS TotalCheltuit
FROM Client c, Bilet b, Rezervare r
WHERE c.cod_c = b.cod_c
  AND b.cod_b = r.cod_b
GROUP BY c.nume_client
HAVING SUM(b.pret - b.reducere) > 50;

--Afiseaza codul si data-ora proiectiilor
--care incep dupa ora 19:00
SELECT
    cod_p AS CodProiectie,
    dt AS DataOra
FROM Proiectie
WHERE CONVERT(TIME, dt) > '19:00:00';

IF OBJECT_ID('VersiuneDB', 'U') IS NULL
BEGIN
    CREATE TABLE VersiuneDB (
        versiune_curenta INT
    );
    INSERT INTO VersiuneDB VALUES (0);
END;
GO

ALTER PROCEDURE do_proc_1
AS
BEGIN
    PRINT N'Modific coloana pret din INT în DECIMAL(6,2) in tabelul Bilet';
    ALTER TABLE Bilet
    ALTER COLUMN pret DECIMAL(6,2);

    UPDATE VersiuneDB SET versiune_curenta = 1;
    PRINT N'Versiunea actualizata la 1';
END;
GO

ALTER PROCEDURE undo_proc_1
AS
BEGIN
    PRINT N'Revenire coloana pret la INT in tabelul Bilet';
    ALTER TABLE Bilet
    ALTER COLUMN pret INT;

    UPDATE VersiuneDB SET versiune_curenta = 0;
    PRINT N'Versiunea revenita la 0';
END;
GO

ALTER PROCEDURE do_proc_2
AS
BEGIN
    PRINT N'Adaug constrangere DEFAULT pentru coloana reducere din tabelul Bilet';

    ALTER TABLE Bilet
    ADD CONSTRAINT DF_Bilet_Reducere DEFAULT 0 FOR reducere;

    UPDATE VersiuneDB SET versiune_curenta = 2;
    PRINT N'Versiunea actualizata la 2';
END;
GO

ALTER PROCEDURE undo_proc_2
AS
BEGIN
    PRINT N'Sterg constrangerea DEFAULT pentru coloana reducere din tabelul Bilet';

    ALTER TABLE Bilet
    DROP CONSTRAINT DF_Bilet_Reducere;

    UPDATE VersiuneDB SET versiune_curenta = 1;
    PRINT N'Versiunea revenita la 1';
END;
GO

CREATE PROCEDURE do_proc_3
AS
BEGIN
    PRINT N'Creez tabelul Feedback';
    CREATE TABLE Feedback (
        id_feedback INT PRIMARY KEY IDENTITY,
        cod_c INT FOREIGN KEY REFERENCES Client(cod_c)
            ON DELETE CASCADE
            ON UPDATE CASCADE,
        cod_f INT FOREIGN KEY REFERENCES Filme(cod_f)
            ON DELETE CASCADE
            ON UPDATE CASCADE,
        rating INT CHECK (rating BETWEEN 1 AND 10),
        comentariu VARCHAR(255)
    );

    UPDATE VersiuneDB SET versiune_curenta = 3;
    PRINT N'Versiunea actualizată la 3';
END;
GO

CREATE PROCEDURE undo_proc_3
AS
BEGIN
    PRINT N'Șterg tabelul Feedback';
    DROP TABLE Feedback;

    UPDATE VersiuneDB SET versiune_curenta = 2;
    PRINT N'Versiunea revenită la 2';
END;
GO

ALTER PROCEDURE do_proc_4
AS
BEGIN
    PRINT N'Adaug coloana rating în tabelul Filme';
    ALTER TABLE Filme
    ADD rating INT;

    UPDATE VersiuneDB SET versiune_curenta = 4;
    PRINT N'Versiunea actualizata la 4';
END;
GO

ALTER PROCEDURE undo_proc_4
AS
BEGIN
    PRINT N'Sterg coloana rating din tabelul Filme';
    ALTER TABLE Filme
    DROP COLUMN rating;

    UPDATE VersiuneDB SET versiune_curenta = 3;
    PRINT N'Versiunea revenita la 3';
END;
GO

ALTER PROCEDURE do_proc_5
AS
BEGIN
    PRINT N'Adaug FK intre Rezervare si Bilet';
    ALTER TABLE Rezervare
    ADD CONSTRAINT fk_Rezervare_Client FOREIGN KEY (cod_b)
        REFERENCES Bilet(cod_b)
        ON DELETE CASCADE
        ON UPDATE CASCADE;

    UPDATE VersiuneDB SET versiune_curenta = 5;
    PRINT N'Versiunea actualizata la 5';
END;
GO

ALTER PROCEDURE undo_proc_5
AS
BEGIN
    PRINT N'Elimin FK intre Rezervare si Bilet';
    ALTER TABLE Rezervare
    DROP CONSTRAINT fk_Rezervare_Client;

    UPDATE VersiuneDB SET versiune_curenta = 4;
    PRINT N'Versiunea revenita la 4';
END;
GO

ALTER PROCEDURE main
    @versiune_dorita INT
AS
BEGIN
    IF @versiune_dorita IS NULL
    BEGIN
        PRINT N'Eroare: specifica o versiune valida (0–5).';
        RETURN;
    END

    IF @versiune_dorita NOT IN (0,1,2,3,4,5)
    BEGIN
        PRINT N'Eroare: versiune invalida.';
        RETURN;
    END

    DECLARE @versiune_curenta INT;
    SELECT @versiune_curenta = versiune_curenta FROM VersiuneDB;

    PRINT N'Versiune curenta: ' + CAST(@versiune_curenta AS NVARCHAR(10));
    PRINT N'Versiune dorita: ' + CAST(@versiune_dorita AS NVARCHAR(10));

    IF @versiune_curenta = @versiune_dorita
    BEGIN
        PRINT N'Baza este deja la versiunea dorita.';
        RETURN;
    END

    IF @versiune_curenta < @versiune_dorita
    BEGIN
        WHILE @versiune_curenta < @versiune_dorita
        BEGIN
            IF @versiune_curenta = 0 EXEC do_proc_1;
            ELSE IF @versiune_curenta = 1 EXEC do_proc_2;
            ELSE IF @versiune_curenta = 2 EXEC do_proc_3;
            ELSE IF @versiune_curenta = 3 EXEC do_proc_4;
            ELSE IF @versiune_curenta = 4 EXEC do_proc_5;

            SELECT @versiune_curenta = versiune_curenta FROM VersiuneDB;
        END
    END
    ELSE
    BEGIN
        WHILE @versiune_curenta > @versiune_dorita
        BEGIN
            IF @versiune_curenta = 5 EXEC undo_proc_5;
            ELSE IF @versiune_curenta = 4 EXEC undo_proc_4;
            ELSE IF @versiune_curenta = 3 EXEC undo_proc_3;
            ELSE IF @versiune_curenta = 2 EXEC undo_proc_2;
            ELSE IF @versiune_curenta = 1 EXEC undo_proc_1;

            SELECT @versiune_curenta = versiune_curenta FROM VersiuneDB;
        END
    END

    PRINT N'Migrare completa cu succes!';
END;
GO

EXEC main @versiune_dorita = 5;
SELECT * FROM VersiuneDB;
SELECT * FROM Filme
EXEC main @versiune_dorita = 13;

SELECT * FROM Client
SELECT * FROM Bilet

IF OBJECT_ID('dbo.Legaturi_Eliminate', 'U') IS NULL
BEGIN
    CREATE TABLE dbo.Legaturi_Eliminate (
        NumeTabelSt VARCHAR(100),
        IdSt INT,
        NumeTabelDr VARCHAR(100),
        IdDr INT,
        DataEliminare DATETIME DEFAULT GETDATE()
    );
END
GO

IF OBJECT_ID('dbo.sp_ReproiectareBD', 'P') IS NOT NULL
    DROP PROCEDURE dbo.sp_ReproiectareBD;
GO

CREATE PROCEDURE dbo.sp_ReproiectareBD
AS
BEGIN
    SET NOCOUNT ON;
    PRINT '--- Incep reproiectarea bazei de date ---';

    DECLARE @DatabaseName NVARCHAR(128) = DB_NAME();
    DECLARE @Step INT = 1;
    DECLARE @fkName NVARCHAR(200);
    DECLARE @sql NVARCHAR(MAX);

    -----------------------------------------------------------------
    -- Transformare 1: Cinema(1)-Sala(N) -> Cinema(N:1)
    -----------------------------------------------------------------
    BEGIN TRY
        BEGIN TRANSACTION;
        PRINT 'Transformare: Cinema(1)-Sala(N) -> Cinema(N:1) (adaug cod_sala in Cinema)';

        -- Adaugam coloana cod_sala daca nu exista
        PRINT 'Verificare si adaugare coloana cod_sala in Cinema';
        SET @sql = N'IF COL_LENGTH(''Cinema'', ''cod_sala'') IS NULL 
                        ALTER TABLE Cinema ADD cod_sala INT NULL;';
        EXEC sp_executesql @sql;

        -- Populare Cinema.cod_sala daca exista tabelele si coloanele necesare
        IF OBJECT_ID('Cinema','U') IS NOT NULL AND OBJECT_ID('Sala','U') IS NOT NULL
            AND COL_LENGTH('Cinema','cod_cn') IS NOT NULL AND COL_LENGTH('Sala','cod_cn') IS NOT NULL
        BEGIN
            PRINT 'Populare coloana cod_sala in Cinema pe baza Sala';
            SET @sql = N'
                UPDATE cn
                SET cn.cod_sala = s.MaxSala
                FROM Cinema cn
                CROSS APPLY (
                    SELECT MAX(s.cod_sala) AS MaxSala
                    FROM Sala s
                    WHERE s.cod_cn = cn.cod_cn
                ) s;';
            EXEC sp_executesql @sql;

            PRINT 'Inserare in Legaturi_Eliminate pentru Sala';
            SET @sql = N'
                INSERT INTO dbo.Legaturi_Eliminate (NumeTabelSt, IdSt, NumeTabelDr, IdDr)
                SELECT ''Cinema'', s.cod_cn, ''Sala'', s.cod_sala
                FROM Sala s;';
            EXEC sp_executesql @sql;

            -- Stergere FK Sala->Cinema
            PRINT 'Stergere FK Sala->Cinema';
            SELECT @fkName = fk.name
            FROM sys.foreign_keys fk
            JOIN sys.objects o ON fk.parent_object_id = o.object_id
            WHERE o.name = 'Sala' AND fk.referenced_object_id = OBJECT_ID('Cinema');

            IF @fkName IS NOT NULL
            BEGIN
                SET @sql = N'ALTER TABLE Sala DROP CONSTRAINT [' + @fkName + '];';
                EXEC sp_executesql @sql;
            END

            -- Stergere coloana Sala.cod_cn
            PRINT 'Stergere coloana cod_cn din Sala';
            SET @sql = N'IF COL_LENGTH(''Sala'',''cod_cn'') IS NOT NULL
                            ALTER TABLE Sala DROP COLUMN cod_cn;';
            EXEC sp_executesql @sql;
        END

        COMMIT TRANSACTION;

        -- Backup
        SET @sql = N'BACKUP DATABASE [' + @DatabaseName + '] TO DISK = N''C:\BackupsDB\' + @DatabaseName + '_Step' + CAST(@Step AS NVARCHAR(10)) + '.bak''';
        EXEC sp_executesql @sql;
        SET @Step += 1;

    END TRY
    BEGIN CATCH
        IF XACT_STATE() <> 0 ROLLBACK TRANSACTION;
        THROW;
    END CATCH

    -----------------------------------------------------------------
    -- Transformare 2: Sala(1)-Loc(N) -> SalaLoc (M:N)
    -----------------------------------------------------------------
    BEGIN TRY
        BEGIN TRANSACTION;
        PRINT 'Transformare: Sala(1)-Loc(N) -> SalaLoc (M:N)';

        -- Creare tabel SalaLoc
        PRINT 'Creare tabela SalaLoc daca nu exista';
        SET @sql = N'IF OBJECT_ID(''dbo.SalaLoc'',''U'') IS NULL
                        CREATE TABLE dbo.SalaLoc (
                            cod_sala INT NOT NULL,
                            cod_loc INT NOT NULL,
                            CONSTRAINT pk_SalaLoc PRIMARY KEY (cod_sala, cod_loc)
                        );';
        EXEC sp_executesql @sql;

        -- Populare SalaLoc doar daca Loc.cod_sala exista
        IF COL_LENGTH('Loc','cod_sala') IS NOT NULL
        BEGIN
            PRINT 'Populare tabela SalaLoc din Loc';
            SET @sql = N'
                INSERT INTO dbo.SalaLoc (cod_sala, cod_loc)
                SELECT cod_sala, cod_loc
                FROM Loc
                WHERE cod_sala IS NOT NULL
                AND NOT EXISTS (
                    SELECT 1 FROM dbo.SalaLoc sl WHERE sl.cod_sala = Loc.cod_sala AND sl.cod_loc = Loc.cod_loc
                );';
            EXEC sp_executesql @sql;

            PRINT 'Inserare in Legaturi_Eliminate pentru Loc';
            SET @sql = N'
                INSERT INTO dbo.Legaturi_Eliminate (NumeTabelSt, IdSt, NumeTabelDr, IdDr)
                SELECT ''Sala'', cod_sala, ''Loc'', cod_loc
                FROM Loc
                WHERE cod_sala IS NOT NULL;';
            EXEC sp_executesql @sql;

            -- Stergere FK Loc->Sala
            PRINT 'Stergere FK Loc->Sala';
            SELECT @fkName = fk.name
            FROM sys.foreign_keys fk
            JOIN sys.objects o ON fk.parent_object_id = o.object_id
            WHERE o.name = 'Loc' AND fk.referenced_object_id = OBJECT_ID('Sala');

            IF @fkName IS NOT NULL
            BEGIN
                SET @sql = N'ALTER TABLE Loc DROP CONSTRAINT [' + @fkName + '];';
                EXEC sp_executesql @sql;
            END

            -- Stergere coloana Loc.cod_sala
            PRINT 'Stergere coloana cod_sala din Loc';
            SET @sql = N'IF COL_LENGTH(''Loc'',''cod_sala'') IS NOT NULL
                            ALTER TABLE Loc DROP COLUMN cod_sala;';
            EXEC sp_executesql @sql;
        END

        COMMIT TRANSACTION;

        -- Backup
        SET @sql = N'BACKUP DATABASE [' + @DatabaseName + '] TO DISK = N''C:\BackupsDB\' + @DatabaseName + '_Step' + CAST(@Step AS NVARCHAR(10)) + '.bak''';
        EXEC sp_executesql @sql;
        SET @Step += 1;

    END TRY
    BEGIN CATCH
        IF XACT_STATE() <> 0 ROLLBACK TRANSACTION;
        THROW;
    END CATCH

    -----------------------------------------------------------------
    -- Transformare 3: CinemaFilme(M:N) -> Cinema.cod_f (1:N)
    -----------------------------------------------------------------
    BEGIN TRY
        BEGIN TRANSACTION;
        PRINT 'Transformare: CinemaFilme(M:N) -> Cinema.cod_f (1:N)';

        -- Adaugare coloana Cinema.cod_f
        PRINT 'Adaugare coloana cod_f in Cinema daca nu exista';
        SET @sql = N'IF COL_LENGTH(''Cinema'', ''cod_f'') IS NULL
                        ALTER TABLE Cinema ADD cod_f INT NULL;';
        EXEC sp_executesql @sql;

        -- Populare Cinema.cod_f doar daca tabela CinemaFilme exista
        IF OBJECT_ID('CinemaFilme','U') IS NOT NULL
        BEGIN
            PRINT 'Populare coloana cod_f in Cinema din CinemaFilme';
            SET @sql = N'
                UPDATE cn
                SET cn.cod_f = sub.MaxCodF
                FROM Cinema cn
                CROSS APPLY (
                    SELECT MAX(cf.cod_f) AS MaxCodF
                    FROM CinemaFilme cf
                    WHERE cf.cod_cn = cn.cod_cn
                ) sub;';
            EXEC sp_executesql @sql;

            PRINT 'Inserare in Legaturi_Eliminate pentru CinemaFilme';
            SET @sql = N'
                INSERT INTO dbo.Legaturi_Eliminate (NumeTabelSt, IdSt, NumeTabelDr, IdDr)
                SELECT ''Cinema'', cf.cod_cn, ''Filme'', cf.cod_f
                FROM CinemaFilme cf
                WHERE cf.cod_f <> (
                    SELECT MAX(cf2.cod_f) FROM CinemaFilme cf2 WHERE cf2.cod_cn = cf.cod_cn
                );';
            EXEC sp_executesql @sql;

            PRINT 'Stergere tabela CinemaFilme';
            SET @sql = N'DROP TABLE dbo.CinemaFilme;';
            EXEC sp_executesql @sql;
        END

        -- Adaugare FK Cinema->Filme
        PRINT 'Adaugare FK Cinema->Filme';
        IF NOT EXISTS (
            SELECT 1 FROM sys.foreign_keys fk WHERE fk.parent_object_id = OBJECT_ID('Cinema') AND fk.referenced_object_id = OBJECT_ID('Filme')
        )
        BEGIN
            SET @sql = N'ALTER TABLE Cinema
                        ADD CONSTRAINT fk_Cinema_Filme FOREIGN KEY (cod_f)
                        REFERENCES Filme (cod_f);';
            EXEC sp_executesql @sql;
        END

        COMMIT TRANSACTION;

        -- Backup
        SET @sql = N'BACKUP DATABASE [' + @DatabaseName + '] TO DISK = N''C:\BackupsDB\' + @DatabaseName + '_Step' + CAST(@Step AS NVARCHAR(10)) + '.bak''';
        EXEC sp_executesql @sql;
        SET @Step += 1;

    END TRY
    BEGIN CATCH
        IF XACT_STATE() <> 0 ROLLBACK TRANSACTION;
        THROW;
    END CATCH

    -----------------------------------------------------------------
    -- Transformare 4: Filme(1)-Proiectie(N) -> Filme.cod_p (1:1)
    -----------------------------------------------------------------
    BEGIN TRY
        BEGIN TRANSACTION;
        PRINT 'Transformare: Filme(1)-Proiectie(N) -> Filme.cod_p (1:1)';

        -- Adaugare coloana Filme.cod_p
        PRINT 'Adaugare coloana cod_p in Filme daca nu exista';
        SET @sql = N'IF COL_LENGTH(''Filme'', ''cod_p'') IS NULL
                        ALTER TABLE Filme ADD cod_p INT NULL;';
        EXEC sp_executesql @sql;

        -- Populare Filme.cod_p
        IF OBJECT_ID('Filme','U') IS NOT NULL AND OBJECT_ID('Proiectie','U') IS NOT NULL
            AND COL_LENGTH('Filme','cod_f') IS NOT NULL AND COL_LENGTH('Proiectie','cod_f') IS NOT NULL
        BEGIN
        PRINT 'Populare coloana cod_p in Filme pe baza Proiectie';
            SET @sql = N'
                UPDATE f
                SET cod_p = sub.MaxCodP
                FROM Filme f
                CROSS APPLY (
                    SELECT MAX(p.cod_p) AS MaxCodP
                    FROM Proiectie p
                    WHERE p.cod_f = f.cod_f
                ) sub;';
            EXEC sp_executesql @sql;

            PRINT 'Inserare in Legaturi_Eliminate pentru Proiectie';
            SET @sql = N'
                INSERT INTO dbo.Legaturi_Eliminate (NumeTabelSt, IdSt, NumeTabelDr, IdDr)
                SELECT ''Filme'', p.cod_f, ''Proiectie'', p.cod_p
                FROM Proiectie p
                WHERE p.cod_p <> (
                    SELECT MAX(p2.cod_p) FROM Proiectie p2 WHERE p2.cod_f = p.cod_f
                );';
            EXEC sp_executesql @sql;

            -- Stergere FK Proiectie->Filme
            PRINT 'Stergere FK Proiectie->Filme';
            SELECT @fkName = fk.name
            FROM sys.foreign_keys fk
            JOIN sys.objects o ON fk.parent_object_id = o.object_id
            WHERE o.name = 'Proiectie' AND fk.referenced_object_id = OBJECT_ID('Filme');

            IF @fkName IS NOT NULL
            BEGIN
                SET @sql = N'ALTER TABLE Proiectie DROP CONSTRAINT [' + @fkName + '];';
                EXEC sp_executesql @sql;
            END

            -- Stergere coloana Proiectie.cod_f
            PRINT 'Stergere coloana cod_f din Proiectie';
            SET @sql = N'IF COL_LENGTH(''Proiectie'',''cod_f'') IS NOT NULL
                            ALTER TABLE Proiectie DROP COLUMN cod_f;';
            EXEC sp_executesql @sql;
        END

        -- UNIQUE Filme.cod_p
        PRINT 'Adaugare UNIQUE pe Filme.cod_p';
        SET @sql = N'IF NOT EXISTS (SELECT 1 FROM sys.indexes WHERE object_id = OBJECT_ID(''Filme'') AND is_unique = 1 AND name = ''UQ_Filme_cod_p'')
                        ALTER TABLE Filme ADD CONSTRAINT UQ_Filme_cod_p UNIQUE (cod_p);';
        EXEC sp_executesql @sql;

        -- FK Filme->Proiectie
        PRINT 'Adaugare FK Filme->Proiectie';
        SET @sql = N'IF NOT EXISTS (SELECT 1 FROM sys.foreign_keys fk WHERE fk.parent_object_id = OBJECT_ID(''Filme'') AND fk.referenced_object_id = OBJECT_ID(''Proiectie''))
                        ALTER TABLE Filme
                        ADD CONSTRAINT fk_Filme_Proiectie FOREIGN KEY (cod_p)
                        REFERENCES Proiectie (cod_p);';
        EXEC sp_executesql @sql;

        COMMIT TRANSACTION;

        -- Backup
        SET @sql = N'BACKUP DATABASE [' + @DatabaseName + '] TO DISK = N''C:\BackupsDB\' + @DatabaseName + '_Step' + CAST(@Step AS NVARCHAR(10)) + '.bak''';
        EXEC sp_executesql @sql;
        SET @Step += 1;

    END TRY
    BEGIN CATCH
        IF XACT_STATE() <> 0 ROLLBACK TRANSACTION;
        THROW;
    END CATCH

    PRINT '--- Reproiectare finalizata cu succes. ---';
END;
GO



-- Executie procedura
EXEC dbo.sp_ReproiectareBD;
GO

-- Afisam legaturile eliminate
SELECT * FROM dbo.Legaturi_Eliminate ORDER BY DataEliminare DESC;
GO


SELECT TOP 10 * FROM Sala;

USE master;
GO


ALTER DATABASE Cinematograf3
SET SINGLE_USER WITH ROLLBACK IMMEDIATE;
GO

RESTORE DATABASE Cinematograf3
FROM DISK = 'C:\BackupsDB\Baza_Originala'
WITH REPLACE;
GO

ALTER DATABASE Cinematograf3
SET MULTI_USER;
GO

CREATE TABLE CinemaFilme_Log (
    cod_cn INT,
    cod_f INT,
    operatiune VARCHAR(10),
    data_operatiune DATETIME DEFAULT GETDATE(),
    user_sql NVARCHAR(100) DEFAULT SUSER_SNAME()
);

ALTER FUNCTION dbo.fn_ValidCinemaFilme (
    @cod_cn INT,
    @cod_f INT
)
RETURNS BIT
AS
BEGIN
    IF EXISTS (SELECT 1 FROM Cinema WHERE cod_cn = @cod_cn)
       AND EXISTS (SELECT 1 FROM Filme WHERE cod_f = @cod_f)
        RETURN 1;
    RETURN 0;
END;

-- crud creare
ALTER PROCEDURE dbo.sp_CinemaFilme_Insert
    @cod_cn INT,
    @cod_f INT,
    @rezultat NVARCHAR(100) OUTPUT
AS
BEGIN
    BEGIN TRY
        IF dbo.fn_ValidCinemaFilme(@cod_cn, @cod_f) = 1
        BEGIN
            IF NOT EXISTS (
                SELECT 1 FROM CinemaFilme 
                WHERE cod_cn = @cod_cn AND cod_f = @cod_f
            )
            BEGIN
                INSERT INTO CinemaFilme (cod_cn, cod_f)
                VALUES (@cod_cn, @cod_f);
                SET @rezultat = 'Insert reusit';
            END
            ELSE
                SET @rezultat = 'Relatia exista deja';
        END
        ELSE
            SET @rezultat = 'Cinema sau Film invalid';
    END TRY
    BEGIN CATCH
        SET @rezultat = ERROR_MESSAGE();
    END CATCH
END;


--read
CREATE PROCEDURE dbo.sp_CinemaFilme_Select
AS
BEGIN
    SELECT cf.cod_cn, cf.cod_f, c.adresa AS Cinema, f.titlu AS Film
    FROM CinemaFilme cf
    JOIN Cinema c ON cf.cod_cn = c.cod_cn
    JOIN Filme f ON cf.cod_f = f.cod_f;
END


--update
ALTER PROCEDURE dbo.sp_CinemaFilme_Update
    @cod_cn INT,
    @cod_f INT,
    @new_cod_cn INT,
    @new_cod_f INT,
    @rezultat NVARCHAR(100) OUTPUT
AS
BEGIN
    IF EXISTS (SELECT 1 FROM CinemaFilme WHERE cod_cn=@cod_cn AND cod_f=@cod_f)
    BEGIN
        IF dbo.fn_ValidCinemaFilme(@new_cod_cn, @new_cod_f) = 1
        BEGIN
            UPDATE CinemaFilme
            SET cod_cn = @new_cod_cn,
                cod_f = @new_cod_f
            WHERE cod_cn = @cod_cn AND cod_f = @cod_f;

            SET @rezultat = 'Update reusit';
        END
        ELSE
            SET @rezultat = 'Cinema sau Film invalid';
    END
    ELSE
        SET @rezultat = 'Relatia nu exista';
END;



--delete
ALTER PROCEDURE dbo.sp_CinemaFilme_Delete
    @cod_cn INT,
    @cod_f INT,
    @rezultat NVARCHAR(100) OUTPUT
AS
BEGIN
    IF EXISTS (SELECT 1 FROM CinemaFilme WHERE cod_cn=@cod_cn AND cod_f=@cod_f)
    BEGIN
        DELETE FROM CinemaFilme
        WHERE cod_cn = @cod_cn AND cod_f = @cod_f;

        SET @rezultat = 'Delete reusit';
    END
    ELSE
        SET @rezultat = 'Relatia nu exista';
END;



--trigger update
CREATE TRIGGER trg_CinemaFilme_Update
ON CinemaFilme
AFTER UPDATE
AS
BEGIN
    INSERT INTO CinemaFilme_Log (cod_cn, cod_f, operatiune)
    SELECT cod_cn, cod_f, 'UPDATE'
    FROM deleted;
END

--trigger delete
CREATE TRIGGER trg_CinemaFilme_Delete
ON CinemaFilme
AFTER DELETE
AS
BEGIN
    INSERT INTO CinemaFilme_Log (cod_cn, cod_f, operatiune)
    SELECT cod_cn, cod_f, 'DELETE'
    FROM deleted;
END


--view filme pe cinema
CREATE vw_FilmePeCinema
AS
SELECT cf.cod_cn, c.adresa, cf.cod_f, f.titlu
FROM CinemaFilme cf
JOIN Cinema c ON cf.cod_cn = c.cod_cn
JOIN Filme f ON cf.cod_f = f.cod_f

--view cinema pe film
CREATE VIEW vw_CinemaPeFilm
AS
SELECT cf.cod_f, f.titlu, cf.cod_cn, c.adresa
FROM CinemaFilme cf
JOIN Filme f ON cf.cod_f = f.cod_f
JOIN Cinema c ON cf.cod_cn = c.cod_cn


CREATE NONCLUSTERED INDEX idx_CinemaFilme_cod_cn ON CinemaFilme(cod_cn)
CREATE NONCLUSTERED INDEX idx_CinemaFilme_cod_f ON CinemaFilme(cod_f)
--CREATE NONCLUSTERED INDEX idx_Filme_titlu ON Filme(titlu)
CREATE NONCLUSTERED INDEX idx_Sala_nr_locuri ON Sala(nr_locuri)
CREATE NONCLUSTERED INDEX idx_Cinema_adresa ON Cinema(adresa)

--exemplu insert
DECLARE @rezultat NVARCHAR(100)
EXEC dbo.sp_CinemaFilme_Insert @cod_cn = 1, @cod_f = 3, @rezultat = @rezultat OUTPUT
PRINT @rezultat

--insert invalid
DECLARE @r NVARCHAR(100); EXEC dbo.sp_CinemaFilme_Insert 1, 999, @r OUTPUT; PRINT @r;

SELECT * FROM CinemaFilme

--exemplu read
EXEC dbo.sp_CinemaFilme_Select

--exemplu validare
SELECT dbo.fn_ValidCinemaFilme(1, 1) AS RezultatValidare
SELECT dbo.fn_ValidCinemaFilme(1, 999) AS RezultatValidare




--exemplu update
DECLARE @rezultat NVARCHAR(100)
EXEC dbo.sp_CinemaFilme_Update @cod_cn = 1, @cod_f = 3, @new_cod_cn = 2, @new_cod_f = 12, @rezultat = @rezultat OUTPUT
PRINT @rezultat;

--exemplu delete
DECLARE @rezultat NVARCHAR(100)
EXEC dbo.sp_CinemaFilme_Delete @cod_cn = 1, @cod_f = 1, @rezultat = @rezultat OUTPUT
PRINT @rezultat;

SELECT * FROM CinemaFilme_Log

--view-urile
SELECT * FROM vw_FilmePeCinema
SELECT * FROM vw_CinemaPeFilm





--pentru cod_cn
SELECT * FROM CinemaFilme WHERE cod_cn = 1
--pentru cod_f
SELECT cf.cod_cn, cf.cod_f FROM CinemaFilme cf WHERE cf.cod_f = 2
--pentru nr_locuri
SELECT cod_sala, nr_locuri, cod_cn FROM Sala WHERE nr_locuri > 120
--pentru adresa
SELECT * FROM Cinema WHERE adresa = 'Str. Mihai Eminescu 10'
