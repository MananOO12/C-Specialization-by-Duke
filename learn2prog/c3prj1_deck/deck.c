

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  for(int i = 0; i < hand->n_cards; i++){
    print_card(*hand->cards[i]);
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  if(d->n_cards == 0){
    return 0;
  }
  for(int i = 0; i < d->n_cards; i++){
    if(c.value == d->cards[i]->value && c.suit == d->cards[i]->suit){
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  for(int i = 0; i < d->n_cards; i++){
    int randIndex = random() % (d->n_cards - 1);
    card_t * temp = d->cards[i];
    d->cards[i] = d->cards[randIndex];
    d->cards[randIndex] = temp;
  }
}

void assert_full_deck(deck_t * d) {
  for(int i = 0; i < 52; i++){
    assert(deck_contains(d, card_from_num(i)));
  }
}

void add_card_to(deck_t *deck, card_t c){
  card_t *newC = malloc(sizeof(card_t));
  newC->suit = c.suit;
  newC->value = c.value;

  deck->cards = realloc(deck->cards, (deck->n_cards + 1)*sizeof(*deck->cards));
  deck->cards[deck->n_cards] = newC;
  deck->n_cards++;
}

card_t * add_empty_card(deck_t *deck){
  card_t *empty = malloc(sizeof(card_t));
  empty->suit = 0;
  empty->value = 0;
  add_card_to(deck, *empty);
  free(empty);
  return deck->cards[deck->n_cards - 1];
}

deck_t * make_deck_exclude(deck_t *excluded_cards){
  deck_t *deck = malloc(sizeof(deck_t));
  deck->cards = NULL;
  deck->n_cards = 0;
  
  for(unsigned c = 0; c < 52; c++){
    card_t card = card_from_num(c);
    if(!deck_contains(excluded_cards, card)){
      add_card_to(deck, card);
    }
  }
  return deck;
}

deck_t * build_remaining_deck(deck_t **hands, size_t n_hands){
  deck_t *excluded = malloc(sizeof(deck_t));
  excluded->cards = NULL;
  excluded->n_cards = 0;
  
  for(int ihand = 0; ihand < n_hands; ihand++){
    deck_t *hand = hands[ihand];
    for(int icard = 0; icard < hand->n_cards; icard++){
      card_t *card = hand->cards[icard];
      add_card_to(excluded, *card);
    }
  }
  deck_t *result = make_deck_exclude(excluded);
  free(excluded);
  return result;
}

void free_deck(deck_t *deck){
  free(deck->cards);
}




































































































































































