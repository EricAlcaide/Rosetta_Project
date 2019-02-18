#  Blackjack

# Step 1: import modules
import simplegui
import random

# Step 2: declare some global variables
CANVAS_SIZE = (740, 650)
IMG_CARDS = simplegui.load_image('http://commondatastorage.googleapis.com/codeskulptor-assets/cards.jfitz.png')
IMG_BACK = simplegui.load_image('http://commondatastorage.googleapis.com/codeskulptor-assets/card_back.png')
CARD_WIDTH = 73
CARD_HEIGHT = 98
RANKS = ('A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K')
COLORS = ('Club', 'Spade', 'Heart', 'Diamond')
VALUES = {'A':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, '10':10, 'J':10, 'Q':10, 'K':10}
FONT_OFFSET = 2
TABLE_UPPER_LEFT_CORNER = (CANVAS_SIZE[0] - 200, CANVAS_SIZE[1] - 120)
score_dealer = 0
score_player = 0
message_upper = ''
message_lower = ''
state = 'stop' # There are 2 states: 'stop' and 'running'
deck = None
dealer_hand = None
player_hand = None

# Step 3: create 3 classes: Card, Deck, Hand
class Card:
    def __init__(self, rank, color, exposed = True):
        self.rank = rank
        self.color = color
        self.exposed = exposed
    def __str__(self):
        return "Rank is " + self.rank + ", Color is " + self.color + ", exposed is " + str(self.exposed)
    def get_rank(self):
        return self.rank
    def get_color(self):
        return self.color
    def is_exposed(self):
        return self.exposed
    def expose_it(self):
        self.exposed = True
    def hide_it(self):
        self.exposed = False
        
class Deck:
    def __init__(self):
        self.cards = []
        for color in COLORS:
            for rank in RANKS:
                self.cards.append(Card(rank, color))
        random.shuffle(self.cards)
    def __str__(self):
        for card in self.cards:
            print card
        return ""
    def get_one_card(self):
        return self.cards.pop()
    def get_all_cards(self):
        return self.cards
    
class Hand:
    def __init__(self):
        self.cards = []
    def __str__(self):
        for card in self.cards:
            print card
        return ""
    def get_sum(self):
        sum_cards = 0
        has_ace = False
        for card in self.cards:
            sum_cards += VALUES[card.get_rank()]
            if card.get_rank() == 'A':
                has_ace = True               
        sum_max = sum_cards
        sum_min = sum_cards        
        if has_ace == True:
            if sum_cards + 10 <= 21:
                sum_max += 10
        return sum_max, sum_min              
    def add_one_card(self, deck):
        self.cards.append(deck.get_one_card())
    def hide_one_card(self, index):
        self.cards[index].hide_it()
    def expose_one_card(self, index):
        self.cards[index].expose_it()
    def get_all_cards(self):
        return self.cards
    
# Step 4: add a function to create new game
def new_game():
    global message_upper, message_lower, state, deck, dealer_hand, player_hand
    message_upper = 'This is a new round.'
    message_lower = 'Hit or stand?'
    state = 'running'
    # initialize the deck, dealer's hand and player's hand
    deck = Deck()
    dealer_hand = Hand()
    player_hand = Hand()
    # distribute cards for dealer and player
    for i in range(2):
        dealer_hand.add_one_card(deck)
        player_hand.add_one_card(deck)
    # make the first card of dealer's hand hidden
    dealer_hand.hide_one_card(0)  

# Step 5: create a draw handler
def draw_handler(canvas):
    # add a Title in the canvas
    canvas.draw_text('BlackJack', (225, 80), 80, 'Black')
    canvas.draw_text('BlackJack', (225 - FONT_OFFSET, 80 - FONT_OFFSET), 80, 'Blue')
    # add a table of score in the bottom right corner    
    canvas.draw_polygon([[TABLE_UPPER_LEFT_CORNER[0] + 200, TABLE_UPPER_LEFT_CORNER[1] + 120], [TABLE_UPPER_LEFT_CORNER[0], TABLE_UPPER_LEFT_CORNER[1] + 120], TABLE_UPPER_LEFT_CORNER, [TABLE_UPPER_LEFT_CORNER[0] + 200, TABLE_UPPER_LEFT_CORNER[1]]], 2, 'Yellow')
    canvas.draw_line((TABLE_UPPER_LEFT_CORNER[0], TABLE_UPPER_LEFT_CORNER[1] + 80), (TABLE_UPPER_LEFT_CORNER[0] + 200, TABLE_UPPER_LEFT_CORNER[1] + 80), 2, 'Yellow')
    canvas.draw_line((TABLE_UPPER_LEFT_CORNER[0], TABLE_UPPER_LEFT_CORNER[1] + 40), (TABLE_UPPER_LEFT_CORNER[0] + 200, TABLE_UPPER_LEFT_CORNER[1] + 40), 2, 'Yellow')
    canvas.draw_line((TABLE_UPPER_LEFT_CORNER[0] + 130, TABLE_UPPER_LEFT_CORNER[1] + 40), (TABLE_UPPER_LEFT_CORNER[0] + 130, TABLE_UPPER_LEFT_CORNER[1] + 120), 2, 'Yellow')
    # add 3 labels in the table
    canvas.draw_text('Score', (TABLE_UPPER_LEFT_CORNER[0] + 60, TABLE_UPPER_LEFT_CORNER[1] + 35), 35, 'Black')
    canvas.draw_text('Score', (TABLE_UPPER_LEFT_CORNER[0] + 60 - FONT_OFFSET, TABLE_UPPER_LEFT_CORNER[1] + 35 - FONT_OFFSET), 35, 'Yellow')
    canvas.draw_text('Dealer', (TABLE_UPPER_LEFT_CORNER[0] + 20, TABLE_UPPER_LEFT_CORNER[1] + 75), 35, 'Black')
    canvas.draw_text('Dealer', (TABLE_UPPER_LEFT_CORNER[0] + 20 - FONT_OFFSET, TABLE_UPPER_LEFT_CORNER[1] + 75 - FONT_OFFSET), 35, 'Red')
    canvas.draw_text('Player', (TABLE_UPPER_LEFT_CORNER[0] + 20, TABLE_UPPER_LEFT_CORNER[1] + 113), 35, 'Black')
    canvas.draw_text('Player', (TABLE_UPPER_LEFT_CORNER[0] + 20 - FONT_OFFSET, TABLE_UPPER_LEFT_CORNER[1] + 113 - FONT_OFFSET), 35, 'Orange')
    # add 2 scores in the table
    canvas.draw_text(str(score_dealer), (TABLE_UPPER_LEFT_CORNER[0] + 150, TABLE_UPPER_LEFT_CORNER[1] + 75), 35, 'Black')
    canvas.draw_text(str(score_dealer), (TABLE_UPPER_LEFT_CORNER[0] + 150 - FONT_OFFSET, TABLE_UPPER_LEFT_CORNER[1] + 75 - FONT_OFFSET), 35, 'Red')
    canvas.draw_text(str(score_player), (TABLE_UPPER_LEFT_CORNER[0] + 150, TABLE_UPPER_LEFT_CORNER[1] + 115), 35, 'Black')
    canvas.draw_text(str(score_player), (TABLE_UPPER_LEFT_CORNER[0] + 150 - FONT_OFFSET, TABLE_UPPER_LEFT_CORNER[1] + 115 - FONT_OFFSET), 35, 'Orange')
    # add label for dealer and player
    canvas.draw_text('Dealer', (70, 150), 35, 'Black')
    canvas.draw_text('Dealer', (70 - FONT_OFFSET, 150 - FONT_OFFSET), 35, 'Red')
    canvas.draw_text('Player', (70, 400), 35, 'Black')
    canvas.draw_text('Player', (70 - FONT_OFFSET, 400 - FONT_OFFSET), 35, 'Orange')
    # add 2 message in canvas
    canvas.draw_text(message_upper, (150, 350), 50, 'Black')
    canvas.draw_text(message_upper, (150 - FONT_OFFSET, 350 - FONT_OFFSET), 50, 'Yellow')
    canvas.draw_text(message_lower, (30, 550), 35, 'Black')
    canvas.draw_text(message_lower, (30 - FONT_OFFSET, 550 - FONT_OFFSET), 35, 'Orange')
    # drawing setting
    cards_margin = 30
    dealer_cards_line = 210
    player_cards_line = 460
    index_of_dealer_cards = 0
    index_of_player_cards = 0
    center_in_png = (CARD_WIDTH / 2.0, CARD_HEIGHT / 2.0)
    # draw dealer's cards
    for card in dealer_hand.get_all_cards():
        index_rank = RANKS.index(card.get_rank())
        index_color = COLORS.index(card.get_color())
        if card.is_exposed() == True:
            canvas.draw_image(IMG_CARDS, (center_in_png[0] + index_rank * CARD_WIDTH, center_in_png[1] + index_color * CARD_HEIGHT), (CARD_WIDTH, CARD_HEIGHT), (cards_margin * (index_of_dealer_cards + 1) + center_in_png[0] + CARD_WIDTH * index_of_dealer_cards, dealer_cards_line), (CARD_WIDTH, CARD_HEIGHT))
        else:
            canvas.draw_image(IMG_BACK, (35.5, 48), (71, 96), (center_in_png[0] + cards_margin, dealer_cards_line), (CARD_WIDTH, CARD_HEIGHT))
        index_of_dealer_cards += 1
    # draw player's cards        
    for card in player_hand.get_all_cards():
        index_rank = RANKS.index(card.get_rank())
        index_color = COLORS.index(card.get_color())
        canvas.draw_image(IMG_CARDS, (center_in_png[0] + index_rank * CARD_WIDTH, center_in_png[1] + index_color * CARD_HEIGHT), (CARD_WIDTH, CARD_HEIGHT), (cards_margin * (index_of_player_cards + 1) + center_in_png[0] + CARD_WIDTH * index_of_player_cards, player_cards_line), (CARD_WIDTH, CARD_HEIGHT))
        index_of_player_cards += 1

# Step 6: create 3 button handlers
def btn_deal():
    global score_dealer
    if state == 'running':
        score_dealer += 1
    new_game()

def btn_hit():
    global score_dealer, message_upper, message_lower, state, dealer_hand, player_hand
    if state != 'stop':
        message_upper = ''
        player_hand.add_one_card(deck)
        sum_max, sum_min = player_hand.get_sum()
        if sum_min > 21:
            dealer_hand.expose_one_card(0)
            score_dealer += 1
            message_upper = 'You went bust and lose.'
            message_lower = 'New deal?'
            state = 'stop'

def btn_stand():
    global score_dealer, score_player, message_upper, message_lower, state, dealer_hand, player_hand
    if state != 'stop':        
        player_max, player_min = player_hand.get_sum()
        play_sum = 0
        if player_max <= 21:
            play_sum = player_max
        else:
            play_sum = player_min
        dealer_sum = 0
        while True:
            dealer_max, dealer_min = dealer_hand.get_sum()           
            if dealer_max <= 21:
                dealer_sum = dealer_max
            else:
                dealer_sum = dealer_min
            if dealer_sum >= 17:
                break
            else:
                dealer_hand.add_one_card(deck)
        dealer_hand.expose_one_card(0)
        if dealer_sum > 21:
            score_player += 1
            message_upper = 'Dealer went bust and lose.'
            message_lower = 'You win! New deal?'
            state = 'stop'
        else:
            if dealer_sum < play_sum:
                score_player += 1
                message_upper = 'You win!'
                message_lower = 'New deal?'
                state = 'stop'
            else:
                score_dealer += 1
                message_upper = 'You lose!'
                message_lower = 'New deal?'
                state = 'stop'
                
                
        
# Step 7: create a frame
frame = simplegui.create_frame('Blackjack', CANVAS_SIZE[0], CANVAS_SIZE[1], 150)
frame.set_canvas_background('Green')

# Step 8: register all event handlers 
frame.set_draw_handler(draw_handler)
frame.add_button('Deal', btn_deal, 150)
frame.add_button('Hit', btn_hit, 150)
frame.add_button('Stand', btn_stand, 150)

# Step 9: start a new game
new_game()

# Step 10: start frame
frame.start()