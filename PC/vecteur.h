/*
Date de création : 09/01/2024
Samuel Mongeon : mons2007
Raphael Côté : cotr1509
*/

#ifndef VECTEUR_H
#define VECTEUR_H

#include "iostream"


template <class T>
class Vecteur
{

public:
	// Constructeur
	Vecteur() : capacity(2), size(0), objPtrs(nullptr)
	{
		// cout << "Construction du vecteur" << endl;
		initialize();
	}

	// Destructeur
	~Vecteur()
	{
		// cout << "Destruction du vecteur" << endl;
		clear(true);
	}

	// Méthode d'initialisation du tableau dynamique
	void initialize()
	{
		objPtrs = new T[capacity];
	}

	// Méthode pour afficher un seul item void
	void show(int i, std::ostream &s)
	{
		 T obj = get(i); // Récupérer l'obj de type T

		 if (obj != T{})
		 {
		 	if constexpr (std::is_pointer_v<T>) // S'assurer que get n'a pas retourné un objet null
		 		obj->show(s);
		 }
	}

	// Méthode pour afficher tous les items
	void showAll(std::ostream &s)
	{
		for (int i = 0; i < size; i++)
			show(i, s);
	}

	// Méthode pour ajouter des items
	bool add(T obj)
	{
		// Si le pointeur reçu est null
		// Retourner false
		// if (obj == T{}) return false;

		// Augmenter, si nécessaire la capacité du tableau
		if (size >= capacity)
			doubleCapacity();

		// Ajouter l'obj au prochain index libre
		// Incrémenter la taille (size) utilisée
		objPtrs[size++] = obj;

		return true;
	}

	// Méthode pour récupérer un item
	T &get(int i) const
	{
		if (i >= 0 && i < size)
			return objPtrs[i];

		static T t;
		return t;
	}

	// Méthode pour enlever un item
	T remove(int i)
	{
		// Si l'index ne respecte pas les bornes du tableau
		// Retourner un pointeur null
		static T t;
		if (i < 0 || i >= size)
			return t;

		// Enregistrer le pointeur
		T objToRemove = objPtrs[i];

		// Décrémenter la taille (size)
		size--;

		// Déplacer tous les pointeurs du tableau de 1 vers le début
		// Ce qui va enlever le pointeur à la position i
		for (int j = i; j < size; j++)
			objPtrs[j] = objPtrs[j + 1];

		// Remplacer la dernière valeur par un pointeur null
		objPtrs[size] = T{};

		// Vérifier si on peut réduire l'espace alloué au tableau
		if (capacity > 1 && size < capacity / 2)
		{
			// Créer un nouveau tableau de pointeur
			T *newObjPtrs = new T[capacity / 2];

			// Ajouter les pointeurs
			for (int j = 0; j < size; j++)
			{
				newObjPtrs[j] = objPtrs[j];
			}

			// Libérer la mémoire de l'ancien tableau
			delete[] objPtrs;

			// Utiliser le nouveau tableau
			objPtrs = newObjPtrs;
		}

		// Retourner le pointeur
		return objToRemove;
	}

	// Méthode pour redimensionner la capacité du tableau dynamique
	void resize(int newCapacity)
	{
		if (newCapacity > 0)
		{
			// Création du nouveau tableau dynamique
			T *newObjPtrs = new T[newCapacity];

			// Ajout des pointeurs du tableau courant
			for (int i = 0; i < size; i++)
				newObjPtrs[i] = objPtrs[i];

			// Libérer l'espace mémoire de l'ancien tableau
			delete[] objPtrs;

			// Setter les valeurs des attributs
			objPtrs = newObjPtrs;
			capacity = newCapacity;
		}
	}

	// Méthode de doublement de la capacité du tableau dynamique
	void doubleCapacity()
	{
		resize(capacity * 2);
	}

	// Méthode pour vider le tableau dynamique (le vecteur)
	void clear(bool destroy = false)
	{
		// Supprimer tous les éléments du vecteur
		while (!isEmpty())
			remove(0); // Enlever le premier élément

		// Enlever l'allocation de mémoire du tableau dynamique (vecteur)
		delete[] objPtrs;

		// Détruire ou ré-initialiser le vecteur
		if (destroy)
			objPtrs = nullptr;
		else
			initialize();
	}

	// Getter pour la capacité
	int getCapacity() const
	{
		return capacity;
	}

	// Getter pour la taille (size) du vecteur
	int getSize() const
	{
		return size;
	}

	// Méthode pour déterminer si la tableau est vide
	bool isEmpty() const
	{
		return size == 0;
	}

	// Méthode pour inverser le tableau
	void reverse()
	{
		// Création du nouveau tableau dynamique
		T *newObjPtrs = new T[capacity];

		// Ajout des objets du tableau courant de façon inversée
		int i = 0;
		for (int j = size - 1; j >= 0; j--)
			newObjPtrs[i++] = objPtrs[j];

		// Libérer l'espace mémoire de l'ancien tableau
		delete[] objPtrs;

		// Setter les valeurs des attributs
		objPtrs = newObjPtrs;
	}

	// Surcharge pour accéder à un élément du vecteur
	T &operator[](int i) const
	{
		return get(i);
	}

	// Surcharge pour ajouter un item à la fin du vecteur
	Vecteur<T> &operator+=(T &obj)
	{
		add(obj);
		return *this;
	}

	// Surcharge pour passer à l’item suivant
	void operator++()
	{
		if (current_item < (size - 1))
			current_item++;
	}

	// Surcharge pour passer à l’item précédent
	void operator--()
	{
		if (current_item > 0)
			current_item--;
	}

private:
	// Attributs
	int capacity;
	int size;
	int current_item;
	// Tableau dynamique avec type générique
	T *objPtrs;
};

template <typename T>
void operator<<(std::ostringstream &s, const Vecteur<T> &v)
{
	for (int i = 0; i < v.getSize(); i++)
		s << v[i];
}

template <typename T>
void operator<<(std::ostream &s, const Vecteur<T> &v)
{
	for (int i = 0; i < v.getSize(); i++)
		v[i]->show(s);
}

template <typename T>
void operator>>(std::ifstream &s, const Vecteur<T> &v)
{
	for (int i = 0; i < v.getSize(); i++)
		s >> v[i];
}

#endif
