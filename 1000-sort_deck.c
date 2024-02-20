#include "deck.h"
#include <stdio.h>

/**
 * _strcmp - Compares two strings lexicographically.
 * @str1: The first string.
 * @str2: The second string.
 * Return: 0 if the strings are equal, otherwise the difference in the
 *         first pair of unequal characters.
 */
int _strcmp(const char *str1, char *str2)
{
	size_t i = 0;

	if (str1 == NULL)
	{
		return (0); /* Handle null input gracefully */
	}

	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}

	/* Handle cases where str1 ends first and str2 doesn't */
	if (str1[i] == '\0' && str2[i] != '\0')
	{
		return (-1);
	}

	return (0); /* Strings are equal */
}

/**
 * get_card_position - Calculates the position of a card based on its value.
 * @node: Pointer to a deck_node_t representing the card.
 * Return: The position of the card in the deck (1-52).
 */
int get_card_position(deck_node_t *node)
{
	int value;

	value = node->card->value[0] - '0'; /* Extract numerical value */

	if (value < 50 || value > 57)
	{ /* Check for face card */
		if (_strcmp(node->card->value, "Ace") == 0)
		{
			value = 1;
		} else if (_strcmp(node->card->value, "10") == 0)
		{
			value = 10;
		} else if (_strcmp(node->card->value, "Jack") == 0)
		{
			value = 11;
		} else if (_strcmp(node->card->value, "Queen") == 0)
		{
			value = 12;
		} else if (_strcmp(node->card->value, "King") == 0)
		{
			value = 13;
		}
	}

	return (value + node->card->kind * 13);
}

/**
 * swap_card - Swaps the position of two cards in a doubly linked deck.
 * @card: Pointer to the card to be swapped.
 * @deck: Pointer to the head of the deck.
 * Return: Pointer to the card that was originally before `card`.
 */
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev, *current = card;

	back->next = current->next;
	if (current->next)
	{
		current->next->prev = back;
	}
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*deck = current;

	return (current);
}

/**
 * insertion_sort_deck - Sort doubly-linked deck of integers in ascending order
 * @deck: Pointer to the head of the doubly linked deck to sort.
 */
void insertion_sort_deck(deck_node_t **deck)
{
	deck_node_t *node;
	int value_prev, value_current;

	/* Handle empty or single-element decks */
	if (deck == NULL || (*deck)->next == NULL)
		return;

	/* Start from the second node */
	node = (*deck)->next;

	while (node)
	{
		/* Get values of current and previous nodes */
		if (node->prev)
		{
			value_prev = get_card_position(node->prev);
			value_current = get_card_position(node);
		}

		/* Swap with previous nodes until in correct position */
		while (node->prev && value_prev > value_current)
		{
			value_prev = get_card_position(node->prev);
			value_current = get_card_position(node);
			node = swap_card(node, deck);
		}

		/* Move to the next node */
		node = node->next;
	}
}
/**
 * sort_deck - Sorts a doubly linked deck using the insertion sort algorithm.
 * @deck: Pointer to the head of the doubly linked deck to sort.
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck);
}
