# Github Repo einrichten.

## Schritt 1
- Installiere Git für dein OS https://git-scm.com/
- Erstelle dir einen lokalen Ordner auf deinem OS für das Projekt

## Schritt 2 (optional)
Solltest du hierbei gefragt werden, wer du bist, dann noch folgende Schritte vollziehen
- git config --global user.email "deine Email"
- git config --global user.name "dein Name"
- Schritt 3 Wiederholen!

## Schritt 3
- Navigiere per GitBash in das Verzeichnis, in dem dein Ordner ist.
- Führe folgenden Befehl aus: git clone https://github.com/Webahh/sorting-system "Ordnername"
Damit wird eine aktuelle Kopie des Repos gezogen.

## Schritt 4 (optional)
- Neuen Branch erstellen. Direkt in dem "main" Branch zu arbeiten ist "bad practice" und kann, wenn mehrere Personen an derselben Stelle arbeiten, zu Fehlern führen.
Dabei gibt es mehrere Strategien, wie und wofür ein neuer Branch erstellt wird. Die einfachste Strategie ist es, dass jede Person einen eignen Branch erstellt und nur dort arbeitet und commits erstellt.

1. Sicherstellen, dass man auf dem main Branch ist:

        - git checkout main

2. Neuen Brach erstellen und dahin (von main aus) wechseln

        - git branch [Name des neuen Branches] z.b git branch Peter
        - git checkout [Name des neuen Branches] z.b git checkout Peter

    oder alles in einer Zeile:

        - git checkout -b [Name des neuen Branches] z.b git checkout -b Peter

3. Wenn man wieder eine in anderen Branches wechseln will, dann mit

        - git checkout [Name des Branches] git checkout main oder git checkout Bob

## Schritt 5
Damit kann jetzt lokal gearbeitet werden. Wenn du Änderungen vollziehst, kannst du das wie folgt hochladen bzw. unser OnlineRepo aktualisieren.
- git add "filename" oder git add . (um einfach alles zu aktualisieren)
- git commit -m "Hier Kurzbeschreibung über Änderung eintragen" oder nur git commit und anschließend im einem Texteditor die Nachricht verfassen
- git push

## Schritt 6
Gab es Änderungen des Repos kannst du diese per Pullbefehl herunterladen und dein lokaler Ordner aktualisieren
- git pull

## Schritt 7
Wenn nun alle Personen auf ihren eignen Branches neue commits ins repo gepushed haben, dann können diese commits (am besten im Team) in den main brach mit einem Merge Request übernommen werden.

Dies kann über github oder direkt in git gemacht werden.

Hau rein Brudi

# Projekt Einrichten

1. Richtigen Ordner für die IDE aus Template/Projects kopieren und in Projects/ einfügen

2. Bibliothek einbinden bzw. Umgebungsvariable setzen

Wichtig: Der Ordner Projects/ wird von git ignoriert
