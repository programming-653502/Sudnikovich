#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

struct tnode {                // узел дерева
  char *word;                  // указатель на строку (слово)
  int count;                   // число вхождений
  struct tnode *left;          // левый потомок
  struct tnode *right;         // правый потомок
};

using namespace std;

char withVowels[100];

// Функция добавления узла к дереву
struct tnode *addtree(struct tnode *p, char *w) {
  int cond;
  if(p == NULL) {
    p = (struct tnode *)malloc(sizeof(struct tnode));
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if((cond = strcmp(w, p->word)) == 0)
      p->count++;
  else if(cond < 0)
      p->left = addtree(p->left, w);
  else
     p->right = addtree(p->right, w);
  return p;
}
// Функция удаления поддерева
void freemem(tnode *tree) {
  if(tree!=NULL) {
      freemem(tree->left);
      freemem(tree->right);
      free(tree);
    }
}
// Функция вывода дерева
void treeprint(struct tnode *p) {
  if(p != NULL) {
    treeprint(p->left);
    printf("%d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}

int isVovel(char c){
    int vovel = 0;
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            vovel = 1;
            break;
        default:
            break;
    }
    return vovel;
}

int countOfVowels(string word)
{
    int counter = 0;
    int result;
    for (int i = 0; word[i] != '\0'; i++)
    {
        int vovel = isVovel(word[i]);
        if (vovel == 1)
        {
            counter++;
        }
    }
    if (counter > 3)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

int main() {
  struct tnode *root;
  char word[20];
  strcat(withVowels,"Words that contain more than three vowels: ");
  root = NULL;
  ifstream fin ("5.2.23.txt");
  fin >> word;
  while(1)
  {
      root = addtree(root, word);
      string s = word;

      int result = countOfVowels(s);
      if (result == 1)
      {
          strcat(withVowels,word);
          strcat(withVowels, " , ");
      }
      fin >> word;
      if (s == word)
      {
          break;
      }
      if (!word[0])
      {
          break;
      }
  }
  cout << endl;
  treeprint(root);
  freemem(root);
  cout << withVowels;
  getchar();
  return 0;
}