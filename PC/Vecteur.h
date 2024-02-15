/**
 * @file Vecteur.h
 * @authors COUS1912, CIP2
 * @brief
 * Fichier contenant la définition de la classe
 * de vecteur, une version plus pathétique de
 * celle fournis par STD par défaut.
 *
 * @attention
 * Veuillez noter que l'utilisation des templates
 * fait en sorte que la définition des méthodes doit
 * être dans le fichier .hpp afin que le compilateur
 * puisse déterminé les templates qu'ils doit build
 * pour l'application en particulier. Sinon, le
 * compilateur pense que aucun type n'a été utilisé
 * et n'est pas capable de savoir quel type il doit
 * remplacer le template par.
 * @version 0.1
 * @date 2024-01-08
 * @copyright Copyright (c) 2024
 */
#pragma once

#include <iostream>

///@brief Definie la valeur étant égal à une infinité de capacité total comme 0.
#define CAPACITE_MAX_INFINIE 0
#define DERNIERE_DONNEE _grosseur-1

#define TYPE_EST_UNE_CLASSE (std::is_class<TypeInconnue>::value)
#define TYPE_EST_UN_POINTEUR (std::is_pointer<TypeInconnue>::value)

/// @brief Type inconnue utilisé pour mettre un type temporaire qui sera défini lorsque l'utilisateur créé un objet de vecteur.
/// @tparam TypeInconnue Type.
template <typename TypeInconnue>

/**
 * @brief
 * La classe de vecteur permet de créé des liste
 * permettant de dynamiquement utilisé la mémoire
 * au lieu de mettre une grosseur pré-déterminé
 * dans un tableau. Cette classe utilise un
 * template afin de réellement permettre une
 * réutilisation de la classe peut importe le
 * type de données sauvegardé.
 */
class Vecteur
{
    public:
        /**
         * @brief Construit un nouvelle objet de
         * vecteur. Les tableau sont mise à leurs
         * valeurs minimum par défaut et le
         * vecteur n'a pas de limite (0).
         */
        Vecteur();

        /**
         * @brief Construit un nouvelle objet de
         * vecteur. Les tableau sont mise à leurs
         * valeurs minimum par défaut et une
         * limite de grosseur de sécurité est
         * instauré dans la classe.
         */
        Vecteur(int capaciteMax);

        /**
         * @brief Destructeur. Chaque donnée
         * stocké sera détruite individuellement
         * pour évité de potentielle problème de
         * mémoire puisqu'on ne sait pas quel
         * type est utilisé!
         */
        ~Vecteur();

        /**
         * @brief Permet d'ajouté une donné à la
         * fin de la liste. La liste grossie de
         * façons automatique si la limite de la
         * capacité est atteinte. Si la capacité
         * maximum est atteinte, la fonction
         * retourne une érreur.
         * @param donnee
         * Donnée à ajouter à la liste
         * @return true: réussi à ajouter la donnée.
         * @return false: La capacité maximale de sécurité est atteinte.
         */
        bool Ajouter(const TypeInconnue& donnee);

        /**
         * @brief Permet d'ajouté une donné à la
         * fin de la liste. La liste grossie de
         * façons automatique si la limite de la
         * capacité est atteinte. Si la capacité
         * maximum est atteinte, la fonction
         * retourne une érreur.
         * @param donnee
         * Donnée à ajouter à la liste
         * @return true: réussi à ajouter la donnée.
         * @return false: La capacité maximale de sécurité est atteinte.
         */
        bool Ajouter(TypeInconnue& donnee);

        /**
         * @brief
         * Permet de retirer un élément de la
         * liste dynamique. Le destructeur de
         * l'élément est automatiquement appelé
         * et la grosseur du vecteur diminue en
         * conséquent. Si l'index n'est pas
         * valide, une erreur est retournée.
         * @param index
         * Nombre entier représentent l'index
         * ou se situe la donné à retirer
         * @return true:
         * Donnée retiré avec succès
         * @return false:
         * Une erreur est survenue. l'index n'est
         * pas valide.
         */
        bool Retirer(int index);

        /**
         * @brief
         * Permet de retirer le dernier élément
         * dans la liste dynamique.
         * @return true:
         * Donnée retiré avec succès
         * @return false:
         * Une erreur est survenue.
         */
        bool Retirer();

        /**
         * @brief
         * Permet de lire une donnée à un index
         * donnée. Veuillez faire attention à se
         * que l'index spécifié soit valide.
         * @param index
         * Nombre entier représentent l'index
         * ou se situe la donné à lire
         * @return TypeInconnue
         * La donnée à l'emplacement spécifié de
         * type indéterminé.
         *
         * @attention
         * Si l'index n'est pas valide, une valeure
         * par défaut du type du vecteur est
         * envoyé. Vérifié votre index avant d'appeller
         * cette fonction!
         */
        TypeInconnue DonneAIndex(int index);

        /**
         * @brief
         * Permet de lire une donnée à un index
         * donnée. Veuillez faire attention à se
         * que l'index spécifié soit valide.
         * @param index
         * Nombre entier représentent l'index
         * ou se situe la donné à lire
         * @return TypeInconnue
         * La donnée à l'emplacement spécifié de
         * type indéterminé.
         *
         * @attention
         * Si l'index n'est pas valide, une valeure
         * par défaut du type du vecteur est
         * envoyé. Vérifié votre index avant d'appeller
         * cette fonction!
         */
        TypeInconnue GetItemCourant();

        /**
         * @brief
         * Permet de lire une donnée à un index
         * donnée. Veuillez faire attention à se
         * que l'index spécifié soit valide.
         * @param index
         * Nombre entier représentent l'index
         * ou se situe la donné à lire
         * @return TypeInconnue
         * La donnée à l'emplacement spécifié de
         * type indéterminé.
         *
         * @attention
         * Si l'index n'est pas valide, une valeure
         * par défaut du type du vecteur est
         * envoyé. Vérifié votre index avant d'appeller
         * cette fonction!
         */
        TypeInconnue* DonnePointeurAIndex(int index);

        /// @brief Retourne la grosseur actuel du vecteur. En gros, combien de données sont actuellement sauvegardées.
        /// @return Nombre entier correspondant à la grosseur actuel du vecteur.
        int Grosseur();

        /// @brief Retourne la grosseur actuel du vecteur. En gros, combien de données sont actuellement sauvegardées.
        /// @return Nombre entier correspondant à la grosseur actuel du vecteur.
        int Grosseur() const;

        /// @brief Retourne la capacité total du vecteur pouvant être atteinte avant de devoir doublé de grandeur.
        /// @return Nombre entier correspondant à la grosseur total du vecteur.
        int Capacite();

        /// @brief Dit si un index donnée correspond à une donnée valide.
        /// @param index: Index à vérifier.
        /// @return true: Index est valide.
        /// @return false: Index n'est pas valide.
        bool VerifierIndex(int index);

        /// <summary>
        /// OVERLOAD A
        /// </summary>
        /// <param name="i"></param>
        /// <returns></returns>
        TypeInconnue operator [](int i) const;

        /// <summary>
        /// OVERLOAD B
        /// </summary>
        /// <param name="i"></param>
        /// <returns></returns>
        TypeInconnue& operator [](int i);


        bool SetItemCourant(int index);

        int GetIndexItemCourant();

        /// <summary>
        /// Adds one data at the end of the vector.
        /// </summary>
        /// <param name="donnee"></param>
        /// <returns>true: Succes, false: erreur</returns>
        bool operator+=(const TypeInconnue& donnee);

        /// <summary>
        /// Augment le itemCourant
        /// </summary>
        /// <param name="donnee"></param>
        /// <returns>true: Succes, false: erreur</returns>
        bool operator++();

        /// <summary>
        /// Diminue l'itemCourant
        /// </summary>
        /// <param name="donnee"></param>
        /// <returns>true: Succes, false: erreur</returns>
        bool operator--();

        friend std::ostream& operator<<(std::ostream& os, const Vecteur<TypeInconnue>& vecteur)
        {
            for (int i = 0; i < vecteur.Grosseur(); ++i) {

                if (constexpr TYPE_EST_UN_POINTEUR)
                {
                    os << vecteur[i] << "\n"; // Of course constexpr couldnt help. FUCK
                }
                else
                {
                    os << vecteur[i] << "\n";
                }
            }
            return os;
        }

    private:
        /// @brief valeur interne de la grosseur actuelle de la liste dynamique
        int _grosseur = 0;
        /// @brief capacité total pouvant être atteinte avant de devoir doublé de capacité
        int _capacite = 0;
        /// @brief Limite donnée par l'utilisateur comme façon d'évité de défoncé la mémoire si un problème survient. Infinie par défaut.
        int _capacite_max = CAPACITE_MAX_INFINIE;
        /// @brief Le tableau de données d'un type non déterminé. Peu importe le type, la sauvegarde et le traitement reste le même.
        TypeInconnue* _donnees;

        int _itemCourant = 0;

        /// @brief Mets a jour le tableau pour être deux fois la grandeur actuelle.
        /// @return true: Doublement effectué avec succès.
        /// @return false: La capacité maximal de sécurité est atteinte.
        bool DoubleLaCapacite();
};

















/**
 * @brief Construit un nouvelle objet de
 * vecteur. Les tableau sont mise à leurs
 * valeurs minimum par défaut et le
 * vecteur n'a pas de limite (0).
 */
template <typename TypeInconnue>
Vecteur<TypeInconnue>::Vecteur()
{
    _capacite_max = 0;
    _grosseur = 0;
    _capacite = 0;
}

/**
 * @brief Destructeur. Chaque donnée
 * stocké sera détruite individuellement
 * pour évité de potentielle problème de
 * mémoire puisqu'on ne sait pas quel
 * type est utilisé!
 */
template <typename TypeInconnue>
Vecteur<TypeInconnue>::~Vecteur()
{

    // Rien n'existe dans le tableau. Si on le delete, le program vas avoir des problèmes de pointeurs.
    if(_grosseur == 0 || _capacite == 0)
    {
        return;
    }

    // Delete toutes les données du tableau si elles peuvent être delete.
    for(int i=0; i<=DERNIERE_DONNEE; i++)
    {
        if constexpr TYPE_EST_UNE_CLASSE
        {
            if constexpr TYPE_EST_UN_POINTEUR
            {
                // Détruit uniquement la donnée du tableau si elle est pas un pointeur pointant nul pars.
                if (_donnees[i] != nullptr)
                {
                    // Viens directement delete la donnée en allant la chercher sans le pointeur.
                    _donnees[i]->~remove_pointer_t<TypeInconnue>();
                    delete _donnees[i];
                }
            }
            else
            {
                // Directement appeller le destructeur puisque la classe est directement dans le vecteur et non référencé par pointeur.
                _donnees[i].~TypeInconnue();
            }
        }
        else
        {
            // Aucun delete a faire. Le vecteur est constitué de données réelles et non de pointeurs
        }
    }
    _grosseur = 0;
    _capacite = 0;
    delete[] _donnees;
}

/// @brief Mets a jour le tableau pour être deux fois la grandeur actuelle.
/// @return true: Doublement effectué avec succès.
/// @return false: La capacité maximal de sécurité est atteinte.
template <typename TypeInconnue>
bool Vecteur<TypeInconnue>::DoubleLaCapacite()
{
    if((_capacite > _capacite_max) && (_capacite_max != 0))
    {
        // Limite de sécurité atteinte.
        return false;
    }

    // Augmente juste de 1 si la capacité était de 0. Sinon, c'est doublé.
    if(_capacite == 0) _capacite = 1;
    else _capacite = _capacite * 2;

    // Créé un tableau de grosseur double du même type que le tableau actuel.
    TypeInconnue* nouvelleDonnees = new TypeInconnue[_capacite];

    // Copie toutes les données du tableau actuel dans le nouveau tableau.
    for(int index=0; index < _capacite; index++)
    {
        if(index < _grosseur)
        {
            nouvelleDonnees[index] = _donnees[index];
            // _donnees[index] = 0;
        }
    }
    _donnees = nouvelleDonnees;
    // nouvelleDonnees = NULL;
    return true;
}

/**
 * @brief Permet d'ajouté une donné à la
 * fin de la liste. La liste grossie de
 * façons automatique si la limite de la
 * capacité est atteinte. Si la capacité
 * maximum est atteinte, la fonction
 * retourne une érreur.
 * @param donnee
 * Donnée à ajouter à la liste
 * @return true: réussi à ajouter la donnée.
 * @return false: La capacité maximale de sécurité est atteinte.
 */
template <typename TypeInconnue>
bool Vecteur<TypeInconnue>::Ajouter(TypeInconnue& donnee)
{
    if(_grosseur == _capacite_max && _capacite_max != CAPACITE_MAX_INFINIE)
    {
        // La Capacité de sécurité est atteinte.
        return false;
    }

    // Capacité actuelle atteinte. La grosseur est doublé.
    // Ceci est fait pour évité de toujours créé de nouveau vecteur.
    if(_grosseur == _capacite)
    {
        if(!DoubleLaCapacite())
        {
            // Limite de sécurité atteinte.
            return false;
        }
    }

    // Stockage de la nouvelle donnée
    _donnees[_grosseur] = donnee;
    _grosseur++;
    return true;
}

/**
 * @brief Permet d'ajouté une donné à la
 * fin de la liste. La liste grossie de
 * façons automatique si la limite de la
 * capacité est atteinte. Si la capacité
 * maximum est atteinte, la fonction
 * retourne une érreur.
 * @param donnee
 * Donnée à ajouter à la liste
 * @return true: réussi à ajouter la donnée.
 * @return false: La capacité maximale de sécurité est atteinte.
 */
template <typename TypeInconnue>
bool Vecteur<TypeInconnue>::Ajouter(const TypeInconnue& donnee)
{
    if((_grosseur == _capacite_max) && (_capacite_max != CAPACITE_MAX_INFINIE))
    {
        // La Capacité de sécurité est atteinte.
        return false;
    }

    // Capacité actuelle atteinte. La grosseur est doublé.
    // Ceci est fait pour évité de toujours créé de nouveau vecteur.
    if(_grosseur == _capacite)
    {
        if(!DoubleLaCapacite())
        {
            // Limite de sécurité atteinte.
            return false;
        }
    }

    // Stockage de la nouvelle donnée
    _donnees[_grosseur] = donnee;
    _grosseur++;
    return true;
}

/**
 * @brief
 * Permet de retirer un élément de la
 * liste dynamique. Le destructeur de
 * l'élément est automatiquement appelé
 * et la grosseur du vecteur diminue en
 * conséquent. Si l'index n'est pas
 * valide, une erreur est retournée.
 * @param index
 * Nombre entier représentent l'index
 * ou se situe la donné à retirer
 * @return true:
 * Donnée retiré avec succès
 * @return false:
 * Une erreur est survenue. l'index n'est
 * pas valide.
 */
template <typename TypeInconnue>
bool Vecteur<TypeInconnue>::Retirer(int index)
{
    if(!VerifierIndex(index))
    {
        // Index n'est pas valide.
        return false;
    }

    // Si l'index correspond à la dernière donné, on sauve du temps.
    if(index == DERNIERE_DONNEE)
    {
        return Retirer();
    }

    // Retirer la donné à l'index spécifié.
    // Détruit l'objet que si c'est une classe
    if constexpr TYPE_EST_UNE_CLASSE
    {
        if constexpr TYPE_EST_UN_POINTEUR
        {
            // Détruit uniquement la donnée du tableau si elle est pas un pointeur pointant nul pars.
            if (_donnees[index] != nullptr)
            {
                // Viens directement delete la donnée en allant la chercher sans le pointeur.
                _donnees[index]->~remove_pointer_t<TypeInconnue>();
                delete _donnees[index];
                _donnees[index] = nullptr;
            }
        }
        else
        {
            // Directement appeller le destructeur puisque la classe est directement dans le vecteur et non référencé par pointeur.
            _donnees[index].~TypeInconnue();
        }
    }
    else
    {
        // Aucun delete a faire. Le vecteur est constitué de données réelles et non de pointeurs
    }
    
    for(int i=index; (i)<DERNIERE_DONNEE; i++)
    {
        _donnees[i] = _donnees[i+1];
    }

    // Shifter toutes les pointeurs de 1.
    //for(int i=index; (i+1)<DERNIERE_DONNEE; i++)
    //{
    //    _donnees[i] = _donnees[i+1];
    //}
    _grosseur--;
    return true;
}

/**
 * @brief
 * Permet de retirer le dernier élément
 * dans la liste dynamique.
 * @return true:
 * Donnée retiré avec succès
 * @return false:
 * Une erreur est survenue.
 */
template <typename TypeInconnue>
bool Vecteur<TypeInconnue>::Retirer()
{
    // Aucune donnée ne peut être retiré si y'a pas de donnée pour commencer.
    if(_grosseur == 0)
    {
        return false;
    }

    _grosseur--;
    // Détruit l'objet que si c'est une classe
    if constexpr TYPE_EST_UNE_CLASSE
    {
        if constexpr TYPE_EST_UN_POINTEUR
        {
            // Détruit uniquement la donnée du tableau si elle est pas un pointeur pointant nul pars.
            if (_donnees[_grosseur] != nullptr)
            {
                // Viens directement delete la donnée en allant la chercher sans le pointeur.
                _donnees[_grosseur]->~remove_pointer_t<TypeInconnue>();
                delete _donnees[_grosseur];
            }
        }
        else
        {
            // Directement appeller le destructeur puisque la classe est directement dans le vecteur et non référencé par pointeur.
            _donnees[_grosseur].~TypeInconnue();
        }
    }
    else
    {
        // Aucun delete a faire. Le vecteur est constitué de données réelles et non de pointeurs
    }
    return true;
}

/**
 * @brief
 * Permet de lire une donnée à un index
 * donnée. Veuillez faire attention à se
 * que l'index spécifié soit valide.
 * @param index
 * Nombre entier représentent l'index
 * ou se situe la donné à lire
 * @return TypeInconnue
 * La donnée à l'emplacement spécifié de
 * type indéterminé.
 *
 * @attention
 * Si l'index n'est pas valide, une valeure
 * par défaut du type du vecteur est
 * envoyé. Vérifié votre index avant d'appeller
 * cette fonction!
 */
template <typename TypeInconnue>
TypeInconnue Vecteur<TypeInconnue>::DonneAIndex(int index)
{
    if(!VerifierIndex(index))
    {
        // Index n'est pas valide. Good luck buddy.
        return TypeInconnue();
    }
    return _donnees[index];
}

template <typename TypeInconnue>
TypeInconnue Vecteur<TypeInconnue>::GetItemCourant()
{
    if (_grosseur == 0)
        return NULL;

    return _donnees[_itemCourant];
}


/**
 * @brief
 * Permet de lire une donnée à un index
 * donnée. Veuillez faire attention à se
 * que l'index spécifié soit valide.
 * @param index
 * Nombre entier représentent l'index
 * ou se situe la donné à lire
 * @return TypeInconnue
 * La donnée à l'emplacement spécifié de
 * type indéterminé.
 *
 * @attention
 * Si l'index n'est pas valide, une valeure
 * par défaut du type du vecteur est
 * envoyé. Vérifié votre index avant d'appeller
 * cette fonction!
 */
template <typename TypeInconnue>
TypeInconnue* Vecteur<TypeInconnue>::DonnePointeurAIndex(int index)
{
    if(!VerifierIndex(index))
    {
        // Index n'est pas valide. Good luck buddy.
        return NULL;
    }
    return &_donnees[index];
}

/// @brief Dit si un index donnée correspond à une donnée valide.
/// @param index: Index à vérifier.
/// @return true: Index est valide.
/// @return false: Index n'est pas valide.
template <typename TypeInconnue>
bool Vecteur<TypeInconnue>::VerifierIndex(int index)
{
    if(index < 0)
    {
        // Index ne peut pas être négative
        return false;
    }

    if(_grosseur == 0)
    {
        // Aucune donnée dans le vecteur. Aucun index.
        return false;
    }

    if(index > DERNIERE_DONNEE)
    {
        // Index est endehors de la grosseur actuelle.
        return false;
    }
    return true;
}

/// @brief Retourne la grosseur actuel du vecteur. En gros, combien de données sont actuellement sauvegardées.
/// @return Nombre entier correspondant à la grosseur actuel du vecteur.
template <typename TypeInconnue>
int Vecteur<TypeInconnue>::Grosseur()
{
    return _grosseur;
}

/// @brief Retourne la grosseur actuel du vecteur. En gros, combien de données sont actuellement sauvegardées.
/// @return Nombre entier correspondant à la grosseur actuel du vecteur.
template <typename TypeInconnue>
int Vecteur<TypeInconnue>::Grosseur() const
{
    return _grosseur;
}

/// @brief Retourne la capacité total du vecteur pouvant être atteinte avant de devoir doublé de grandeur.
/// @return Nombre entier correspondant à la grosseur total du vecteur.
template <typename TypeInconnue>
int Vecteur<TypeInconnue>::Capacite()
{
    return _capacite;
}














/// <summary>
/// OVERLOAD A
/// </summary>
/// <param name="i"></param>
/// <returns></returns>
template<typename TypeInconnue>
TypeInconnue Vecteur<TypeInconnue>::operator [](int i) const
{ 
    /*if (!VerifierIndex(i))
    {
        std::cout << "INDEX ERROR" << std::endl;
        return _donnees[0];
    }*/
    return _donnees[i]; 
}

/// <summary>
/// OVERLOAD B
/// </summary>
/// <param name="i"></param>
/// <returns></returns>
template<typename TypeInconnue>
TypeInconnue& Vecteur<TypeInconnue>::operator [](int i) 
{
    if (!VerifierIndex(i))
    {
        std::cout << "INDEX ERROR" << std::endl;
        return _donnees[0];
    }
    return _donnees[i]; 
}


template<typename TypeInconnue>
bool Vecteur<TypeInconnue>::SetItemCourant(int index)
{
    _itemCourant = index;
    return true;
}

template<typename TypeInconnue>
int Vecteur<TypeInconnue>::GetIndexItemCourant()
{
    if (_grosseur == 0) return 0;
    if (_itemCourant > (_grosseur - 1))
    {
        _itemCourant = _grosseur - 1;
    }
    return _itemCourant;
}

/// <summary>
/// Adds one data at the end of the vector.
/// </summary>
/// <param name="donnee"></param>
/// <returns>true: Succes, false: erreur</returns>
template<typename TypeInconnue>
bool Vecteur<TypeInconnue>::operator+=(const TypeInconnue& donnee) {
    return Ajouter(donnee);
}


template<typename TypeInconnue>
bool Vecteur<TypeInconnue>::operator++()
{
    _itemCourant++;
    return true;
}

template<typename TypeInconnue>
bool Vecteur<TypeInconnue>::operator--()
{
    _itemCourant--;
    return true;
}


