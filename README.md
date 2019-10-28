# Cha-ne-compl-te-de-traitement-d-images
La structuration de la chaîne de traitements ici se fera à deux niveaux : - le niveau de segmentation : objets contenus dans l'image masques. ici, toutes les régions correspondantes aux sont bien identifiées et représentées par des - le niveau de post-segmentation : 
- Ici le traitement nous donne des améliorations au niveau de la forme des régions détectées au cours du traitement appliqué à la segmentation (correction des contours, remplissage des trous) et le bruit considérablement réduit. 
- Il est essentiel pour nous de signaler que la pré-segmentation qui devrait être faite bien avant pour la préparation des images à la segmentation proprement dite ne se fera plus car le jeu d’images obtenu est d’une qualité parfaite (fond unique et un bon contraste) car nous n’observons pas de bruits apparents.

FONCTIONNEMENT DU PROGRAMME

Pour utiliser le programme implémenté, l’utilisateur devrait suivre les étapes suivantes :

1) Se placer dans le dossier contenant le code source du programme
2) Copier les images à segmenter directement dans le dossier contenant le code source.
3) Lancer le terminal
4) Exécuter la commande « make » pour compiler le programme
5) Taper la commande : ./tp3
6) Taper le nom de l’image nom_image.extension (Exemple : objets1.jpg)
