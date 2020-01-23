templates

Authors:
Yael Yishay 
General explanation of the exercise:
Realization of a registration form of a student for an additional year of study. The student provides a number of personal details as well as details of his / her studies for the school year in question. The software verifies that the items are valid, including verifying the details of the studies with the information that is known in advance about the study options.
UML:
Validator- Non-template base class. It inherits a simpleValidator (template) and a complexValidator (non template). simpleValidator -  A base class for all tests belonging to a single field. complexValidator -  A base class for all tests belonging to the form, of witch two fields need to match
Main data structures:
The form class contains a vector of fields, and a vector of  complexValidator.
The field class is a template contains a vector of simpleValidator of different types.

Known bugs:
Unknown