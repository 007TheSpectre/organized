# Organized

Organized est un petit programme en C permettant de gerer une liste d'elements
(type, nom et identifiant) grace a un shell interactif. Les types disponibles
sont : `ACTUATOR`, `DEVICE`, `PROCESSOR`, `SENSOR` et `WIRE`.

## Compilation

```bash
make
```

Le binaire `organized` est alors genere a la racine du projet.

## Utilisation

Lancez simplement le programme :

```bash
./organized
```

Le prompt `Workshop >>` apparait et vous permet d'utiliser les commandes
suivantes :

- `add TYPE NAME [TYPE NAME ...]` : ajoute un ou plusieurs elements.
- `del ID [ID ...]` : supprime les elements correspondant aux identifiants donnes.
- `sort [TYPE [-r]] [NAME [-r]] [ID [-r]]` : trie la liste selon un ou plusieurs
  criteres (option `-r` pour un tri inverse).
- `disp` : affiche la liste courante.
- `exit` : quitte le programme.

Les identifiants sont attribues automatiquement a partir de 0 lors de l'ajout
et restent fixes tant que l'element existe.

## Documentation Doxygen

Une configuration Doxygen est fournie (fichier `Doxyfile`).
Pour generer la documentation HTML et LaTeX, assurez-vous de disposer de
`doxygen` (et eventuellement `graphviz` pour les graphes) puis executez :

```bash
doxygen Doxyfile
```

La documentation est ensuite disponible dans le dossier `doc/` (sous
`doc/html` pour la version web).

## Ressources

Le fichier `B-CPE-110_Organized.pdf` decrit plus en detail le sujet du projet.
