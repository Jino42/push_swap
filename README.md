PUSH_SWAP
===

https://www.youtube.com/watch?v=egU3YD8OKbw&feature=youtu.be

Presentation
-
Votre but ? Ecrire deux programmes en C :
• Un premier nommé checker qui prend des entiers en paramètres et qui lit des instructions
sur l’entrée standard. Une fois ces instructions lues, checker les exécute
puis affiche OK si les entiers sont triés, ou KO sinon.
• Un second nommé push_swap qui calcule et affiche sur la sortie standard le plus
petit programme dans le langage des instructions de Push_swap qui trie les entiers
passés en paramètre.

Le but est donc de créer un algorithme de tri.
J'ai pensé l'aglo sur le trajet de retour de l'ecole a chez moi.
Je l'ai codé le lendemain en 2h
J'ai passé néanmoins une vingtaines d'heure pour l'améliorer un peut, ou voir les autres possibilitées

Ses perfemances sont de 5/5 sur les grandes piles (500 nombres)
Et de 4/5 sur les moyennes piles (100 nombres)


But du jeu
==


• Le jeu est constitué de 2 piles nommées a et b.
  • Au départ :
  ◦ a contient un nombre arbitraire d’entiers positifs ou négatifs, sans doublons.
  ◦ b est vide
• Le but du jeu est de trier a dans l’ordre croissant.

• Pour ce faire, on ne dispose que des opérations suivantes :


Instructions
-
| Mnemonic |                               Instruction                     |
|:----------:| ----------------------------------------------------------- |
|sa| swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun. |
|sb| intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun. |
|ss|sa et sb en même temps.|
|pa|push a - prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.|
|pb|push b - prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.|
|ra|rotate a - décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.|
|rb|rotate b - décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.|
|rr|ra et rb en même temps.|
|rra|reverse rotate a - décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.|
|rrb|reverse rotate b - décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier.|
|rrr|rra et rrb en même temps.|

Exemple d'instruction :<br />
<br />
0. Init a & b<br />
[A]:213658<br />
[B]:<br />
<br />
1. SA<br />
[A]:123658<br />
[B]:<br />
<br />
2. PB PB PB<br />
[A]:658<br />
[B]:321<br />
<br />
3. RR<br />
[A]:586<br />
[B]:213<br />
<br />
4. RRR<br />
[A]:658<br />
[B]:321<br />
<br />
5. SA<br />
[A]:568<br />
[B]:321<br />
<br />
6. PA PA PA<br />
[A]:123568<br />
[B]:<br />


Vidéo de présentation : https://www.youtube.com/watch?v=egU3YD8OKbw&feature=youtu.be
