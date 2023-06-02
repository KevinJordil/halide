# Installation

Sur le site officiel de Halide à l'adresse suivante : [https://github.com/halide/Halide/releases](https://github.com/halide/Halide/releases). Téléchargez la version la plus récente de Halide qui correspond à votre système d'exploitation (Windows, macOS ou Linux).

Ouvrez un terminal et décompressez l'archive téléchargée dans un dossier de votre choix.
Ajoutez le chemin vers le dossier contenant les fichiers Halide (par exemple, /chemin_vers_halide/bin) à la variable d'environnement PATH de votre système. Cela permettra à votre système de trouver les exécutables Halide lorsqu'ils seront utilisés.
Vous pouvez également définir la variable d'environnement HALIDE_DIR sur le chemin du dossier Halide pour faciliter l'utilisation de Halide dans votre code.

Installation des packages necessaires pour compiler Halide :

```bash
sudo apt install \
                  clang-tools lld llvm-dev libclang-dev liblld-10-dev \
                  libpng-dev libjpeg-dev libgl-dev \
                  python3-dev python3-numpy python3-scipy python3-imageio python3-pybind11 \
                  libopenblas-dev libeigen3-dev libatlas-base-dev \
                  doxygen ninja-build
```

Installation de la bonne version de CMake :

```bash
sudo apt remove cmake
snap install cmake --classic
hash -r
```

Maintenant la dernière version de cmake est installée. Pour vérifier la version de cmake, exécutez la commande suivante :

```bash
cmake --version
```

Il faut que la version soit supérieure à 3.22.
