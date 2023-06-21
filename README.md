# Halide

Basile Cuneo & Kévin Jordil

## Installation

Pour installer la librairie Halide, nous avons mis en place un script qui permet de simplifier l'installation. Il suffit d'exécuter le script `install_halide.sh` qui se trouve à la racine de ce répertoire.

## Programme

Notre programme permet d'inverser les couleurs d'une image grâce à Halide.

## Compilation

Pour compiler le programme, il suffit de se rendre dans le répertoire `code/halide` et d'exécuter la commande `make`. L'exécutable s'appelle `main`.

## Exécution

Pour exécuter le programme, il faut utiliser la commande `make run` dans le répertoire `code/halide`. Il est necessaire d'exécuter le programme via le Makefile pour que les variables d'environnement soient correctement initialisées.

## Rapport

### Qu'est-ce que halide 

Halide est un langage de programmation intégré au C++ sous forme de librairie et est conçu spécialement pour le traitement d'images et de tableaux. 

Cet outil facilite le développement de code pour les machines modernes et est disponible sur la plupart des architectures de processeurs récents (X86, ARM, MIPS, RISC-V, ...) et utilisable sur tous les systèmes d'exploitations courants (Linux, Windows, MacOS, Android, iOS).

Ce langage fonctionne sur un principe de séparation entre l'algorithme et l'implémentation sous forme de pipeline. L'algorithme est décrit dans un langage de haut niveau et l'implémentation est décrite dans un langage de bas niveau. Cela permet de séparer les préoccupations et de faciliter la réutilisation du code. Pour mettre en place ce pipeline, trois étapes principales entre en compte: la définition des éléments du pipeline, la planification de l'algorithme et la génération du code à la volée puis l'exécution.

Par défaut, Halide permet de générer un code optimisé pour les architectures cibles à la volée (pendant l'exécution du programme). Il est tout de même possible de spécifier des paramètres d'optimisation pour chaque étape du pipeline. Il est également possible de spécifier des paramètres d'optimisation pour chaque architecture cible. Halide permet de générer du code pour plusieurs architectures cibles en même temps. Lors de la compilation à la volée, l'outil va pouvoir mettre en place, par exemple, du multi threading ou encore du SIMD.

La définition des éléments du pipeline consiste à déclarer les variables nécessaires ainsi que les différentes étapes. Des types spécifiques sont existants, comme par exemple: `Halide::Var` pour les variables et `Halide::Func` pour les différentes étapes.

La planification de l'algorithme consiste à expliciter les différentes étapes de calcul à réaliser à partir des `Halide::Func` et `Halide::Var` déclarées au préalable. De plus avec une `Halide::Func` il est possible de spécifier comment manipuler les données en indiquant par exemple `vectorize(x, y)` ou alors `parallel(y)`. Cela peut être pratique lorsque l'on souhaite être plus précis sur l'optimisation du code.

La fonction `compile.jit` pouvant être appelée sur les `Halide::Func` permet la génération à la volée du code nécessaire à l'étape décrite. Comme mentionné plus tôt, des paramètres de compilation peuvent être utilisés.

Finalement, la fonction `realize` également appelée sur les `Halide::Func` permet d'exécuter le pipeline et de récupérer le résultat.

### Comparaison avec OpenCV

Pendant la présentation nous avions montré un exemple avec une inversion des couleurs d'une image avec Halide et OpenCV. Dans notre démonstration nous avions montré que Halide était plus rapide qu'OpenCV. 

Cependant, Bruno nous a fait remarquer que nous avions fait l'inversion des couleurs avec OpenCV avec des boucles for plutôt qu'avec les fonctions de la librairie. Nous avons donc refait les tests avec les fonctions de la librairie OpenCV.

De plus, Alberto Dassati nous a fait remarquer que dans la version de code avec Halide, nous avions inclus la fonction de compilation dans la mesure du temps d'exécution. Nous avons donc pris la mesure du temps d'exécution uniqement pour la fonction `realize`.

De ce fait les résultats changent. Voici les résultats avant modification :
* OpenCV : ~2400ms
* Halide : ~850ms

Voici les résultats après modification :
* OpenCV : ~180ms
* Halide : ~340ms

Nous observons donc que dans cet exemple, Halide est plus lent qu'OpenCV. Lorsque nous avons regardé sur internet, nous avons vu qu'Halide est plus adapté pour faire une suite de modifications bas niveau alors qu'OpenCV est plus adapté pour faire une transformation haut niveau.