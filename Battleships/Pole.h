#pragma once
/**
 * \brief Klasa reprezentuj¹ca pole na planszy w grze.
 *
 * Ta klasa zawiera metody do manipulacji stanami pola.
 */
class Pole
{	
private:
		/**
		* \brief Wskazuje, czy pole zosta³o trafione.
		*/
		bool hit = false;
		/**
		* \brief Wskazuje, czy pole jest zajête.
		*/
		bool occupied = false;
		/**
		* \brief Wskazuje, czy pole jest oznaczone.
		*/
		bool marked = false;
		/**
		* \brief Wskazuje, czy pole jest wolne.
		*/
		bool free_field = false;

		bool sunk = false;
public:
	bool Field_is_hitted();
	bool Field_is_free();
	bool Fiel_is_occupied();
	bool Field_is_marked();
	void SetField();
	void Shot();
	void Set_field_free();
	void Free();
	void Mark();
	void Unmark();
	bool is_sunk();
	void set_sunk();
	void Free_Field_To_False();
};

