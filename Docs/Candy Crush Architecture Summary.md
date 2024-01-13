# Project Architecture

### User Interface (UI) Layer

- **Responsibilities:**
  - Handles user interactions and input.
  - Displays game graphics and visual elements.

- **Components:**
  - UI classes, screens, and elements.
  - User input handlers.
  - Game rendering engine.

### Business Logic Layer

- **Responsibilities:**
  - Manages the game rules and mechanics.
  - Orchestrates interactions between UI and Data layers.
  - Contains game state and logic.

- **Components:**
  - GameController: Controls the overall game flow acting as an interface of the business layer.
  - GameManager: Manages the current game state.
  - Level: Represents individual game levels.
  - BoardManager: Handles board-related operations.
  - Board: Represents the game board.
  - Objective: Defines level objectives.

### Event System

- **Responsibilities:**
  - Facilitates inter-component communication within the Business Logic Layer.
  - Enables potential inter-system communication between UI and Business Logic layers.

- **Components:**
  - Event handling mechanisms.
  - Subscription and notification systems.

### Data Layer

- **Responsibilities:**
  - Manages game data and persistence.
  - Handles storage and retrieval of game information.

- **Components:**
  - Data storage classes.
  - Database interface.

## Interactions

1. **UI to Business Logic:**
   - UI components send user input to the GameController.
   - GameController initiates actions in the GameManager based on user input.

2. **Business Logic to UI:**
   - GameManager updates the game state.
   - UI components retrieve and display updated information from the GameController.
   - Event System notifies UI components about relevant events.

3. **Business Logic to Data:**
   - Business Logic components interacts with the Data Layer for saving or loading game progress.

5. **Event System:**
   - Facilitates communication between different components within the Business Logic Layer.
   - Enables potential communication between Business Logic and UI Layers.

## Flow

1. **User Interaction:**
   - User interacts with the UI, triggering actions.

2. **GameController:**
   - GameController processes user input and directs actions to the GameManager.

3. **GameManager:**
   - Manages the overall game state, including the current level and objectives.
   - Interacts with Level, BoardManager, and other components.
   - Publishes events to the Event System.

4. **BoardManager :**
   - Manages the game board.
   - Publish matching and gravity events to the Event System.

5. **Level :**
   - Handle level-specific logic, such as updating objectives and managing the game board.
   - Subscribe to board modifications events, updates the level objectives accordingly.

6. **UI Updates:**
   - GameManager updates UI components with the latest game state.
   - UI components subscribe to relevant events from the Event System.

7. **Data Interaction:**
   - Business Layer Components may interact with the Data Layer for saving or loading game progress.
