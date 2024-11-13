*** Settings ***
Documentation    Embedded Systems Project Test Cases

*** Test Cases ***
Test Case 1: Check the functionalty of the potentiometer
    [Documentation]    [use an out of range value from the potentiometer ]
    
    [Setup steps]
    connect the arduino to the pc 
    connect the circuit with the components to the arduino uno board
     (Perform the action to be tested)
    use an out of range analogue value from the potentiometer 

     (Verify the expected outcome)
    [Assertion steps]
    the expected outcome is that the led will turn on and the buzzer makes a sound
    outcome:  the red led turn on and the buzzer makes a sound

Test Case 2: if the limits are 0
    [Documentation]    [Both lower and upper limits are 0]
    
    (Set up the test environment)
    [Setup steps]
    connect the arduino to the pc 
    connect the circuit with the components to the arduino uno board

    (Perform the action to be tested)
    [Action steps]
    change the limit for both of the higher and lower limits of the code to 0 from the button

    (Verify the expected outcome)
    [Assertion steps]
    the expected outcome is that the led  will not be on 
    outcome: The led will not turn on 

Test Case 3: [Verfying the limits]
    [Documentation]    [upper and lower limits are equal and greater than 0]
    
    (Set up the test environment)
    [Setup steps]
    connect the arduino to the pc 
    connect the circuit with the components to the arduino uno board

    (Perform the action to be tested)
    [Action steps]
    Change both of the limits to the same value but greater than 0 ex:500
    Use this value for the potentiometer

    (Verify the expected outcome)
    [Assertion steps]
    the expected outcome is that the led will not be on and the buzzer will not make a sound
    outcome: The led and the buzzer don't make any action

Test Case 4: Check the limitts of the potentimeter
    [Documentation]    [rotate the potentiometer]
    
    (Set up the test environment)
    [Setup steps]
    connect the arduino to the pc 
    connect the circuit with the components to the arduino uno board
    (Perform the action to be tested)
    rotate  the potentiometer from the lower to the upper limit

    (Verify the expected outcome)
    [Assertion steps]
    the expected outcome is that  the led and the buzzer will not function  as long as they between the limit  range
    outcome: The led and the buzzer will not function when they are in the limit range

Test Case 5: Check the functionalty of the pushbuttons
    [Documentation]    [press all of the buttons togethers]
    
    [Setup steps]
    connect the arduino to the pc 
    connect the circuit with the components to the arduino uno board
    (Perform the action to be tested)
    press all of the push buttons at the same time 

    (Verify the expected outcome)
    [Assertion steps]
    the expected outcome is that there will be a change in both limits but an inconsistent one because we cannot press all of buttons at the same rate
    outcome: inconsistent change in both limits 

Test Case 6: Check the functionalty of the buzzer for the upper limit
    [Documentation]    [use a value higher than the upper limit to check if the buzzer works correctly]
    
    [Setup steps]
    connect the arduino to the pc 
    connect the circuit with the components to the arduino uno board
    (Perform the action to be tested)
    turn the potentiometer to a bigger value  than the higher limit

    (Verify the expected outcome)
    [Assertion steps]
    the expected outcome is that the led will turn on and the  buzzer will make a sound as soon as the input value gets bigger than the higher limit
    outcome: the led will turn on and the buzzer buzzes as the value gets past the upper limit

Test Case 7: Check the functionalty of the buzzer for the lower limit
    [Documentation]    [use a value that is inferiour than the lower limit to check if the buzzer works correctly]
    
    [Setup steps]
    connect the arduino to the pc 
    connect the circuit with the components to the arduino uno board
    (Perform the action to be tested)
    turn the potentiometer to a smaller value  than the lower limit

    (Verify the expected outcome)
    [Assertion steps]
    the expected outcome is that the led will turn on and the buzzer will make a sound because the given input value is smaller than the lower limit value 
    outcome: the led turns on and the buzzer makes a sound when the value is inferior than the lower limit 

Test Case 8: Check the functionalty of the lcd
    [Documentation]    [Check if the lcd is working properly]
    
    [Setup steps]
    connect the arduino to the pc 
    connect the circuit with the components to the arduino uno board
    (Perform the action to be tested)
    turn the potentiometer to a value in the given range 

    (Verify the expected outcome)
    [Assertion steps]
    the expected outcome is that the led will not turn on and the buzzer won't make a sound as the value is in between the range and the lcd will print ok
    outcome: None of the components do anything and the lcd funtions properly and prints ok

Test Case 9: Check if the higher limit value is included
    [Documentation]    [Check if limit value will be included in the range]
    
    [Setup steps]
    connect the arduino to the pc 
    connect the circuit with the components to the arduino uno board
    (Perform the action to be tested)
    set the higher limit to 700
    turn the potentiometer to the same exact value as the higher limit

    (Verify the expected outcome)
    [Assertion steps]
    the expected outcome is that the led and the buzzer will turn properly to make ure that the limit is included
    outcome: the led and the buzzer function properly 

Test Case 10: Check if the lower limit can be lower than 0
    [Documentation]    [Check if the lower limit value can be past 0]
    
    [Setup steps]
    connect the arduino to the pc 
    connect the circuit with the components to the arduino uno board
    (Perform the action to be tested)
    keep decreasing the lower value limit from the push button 
    make sure to turn the potentiometer to the left and assure that its value is smaller than the lower limit

    (Verify the expected outcome)
    [Assertion steps]
    the expected outcome is that the new lower limit value will be displayed on the lcd and that the circuit will function effeciently
    outcome: the circuit functions effeciently as the value from the potentiometer is smaller than the new lower limit and the new lower limit value is displayed on the lcd   