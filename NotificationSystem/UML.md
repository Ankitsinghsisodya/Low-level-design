# Notification System - Class Diagram

```mermaid
classDiagram
    direction TB

    class INotification {
        <<interface>>
        +getContent() string
    }

    class SimpleNotification {
        -string text
        +SimpleNotification(string msg)
        +getContent() string
    }

    class INotificationDecorator {
        <<abstract>>
        #INotification* notification
        +INotificationDecorator(INotification*)
        +getContent() string*
    }

    class TimeStampDecorator {
        +TimeStampDecorator(INotification*)
        +getContent() string
    }

    class SignatureDecorator {
        -string signature
        +SignatureDecorator(INotification*, string sig)
        +getContent() string
    }

    class INotificationStrategy {
        <<interface>>
        +sendNotification(string content)
    }

    class EmailStrategy {
        -string emailId
        +EmailStrategy(string emailId)
        +sendNotification(string content)
    }

    class SMSStrategy {
        -string mobileNumber
        +SMSStrategy(string mobileNumber)
        +sendNotification(string content)
    }

    class PopUpStrategy {
        +sendNotification(string content)
    }

    class IObserver {
        <<interface>>
        +update()
    }

    class IObservable {
        <<interface>>
        +addObserver(IObserver*)
        +removeObserver(IObserver*)
        +notifyObservers()
    }

    class NotificationObservable {
        -vector~IObserver*~ observers
        -INotification* currentNotification
        +addObserver(IObserver*)
        +removeObserver(IObserver*)
        +notifyObservers()
        +setNotification(INotification*)
        +getNotification() INotification*
        +getNotificationContent() string
    }

    class Logger {
        -NotificationObservable* notificationObservable
        +Logger()
        +update()
    }

    class NotificationEngine {
        -NotificationObservable* notificationObservable
        -vector~INotificationStrategy*~ notificationStrategies
        +NotificationEngine()
        +addNotificationStrategy(INotificationStrategy*)
        +update()
    }

    class NotificationService {
        <<Singleton>>
        -static NotificationService* instance
        -NotificationObservable* observable
        -vector~INotification*~ notifications
        +getInstance() NotificationService*
        +getObservable() NotificationObservable*
        +sendNotification(INotification*)
    }

    INotification <|.. SimpleNotification
    INotification <|.. INotificationDecorator
    INotificationDecorator <|-- TimeStampDecorator
    INotificationDecorator <|-- SignatureDecorator
    INotificationDecorator o-- INotification : wraps

    INotificationStrategy <|.. EmailStrategy
    INotificationStrategy <|.. SMSStrategy
    INotificationStrategy <|.. PopUpStrategy

    IObserver <|.. Logger
    IObserver <|.. NotificationEngine
    IObservable <|.. NotificationObservable

    NotificationObservable o-- IObserver : notifies
    NotificationObservable o-- INotification : holds

    NotificationService *-- NotificationObservable : owns
    NotificationService o-- INotification : stores

    Logger --> NotificationObservable : observes
    NotificationEngine --> NotificationObservable : observes
    NotificationEngine o-- INotificationStrategy : dispatches via

    NotificationService ..> NotificationEngine : triggers via observable
    NotificationService ..> Logger : triggers via observable
```

## Design Patterns Used

| Pattern       | Where                                                                                                                                                         |
| ------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Singleton** | `NotificationService` — single global instance                                                                                                                |
| **Observer**  | `NotificationObservable` (subject) notifies `Logger` and `NotificationEngine` (observers) on every new notification                                           |
| **Decorator** | `TimeStampDecorator` and `SignatureDecorator` wrap an `INotification` to add content at runtime without changing the base class                               |
| **Strategy**  | `NotificationEngine` holds a list of `INotificationStrategy` implementations (`EmailStrategy`, `SMSStrategy`, `PopUpStrategy`) and delegates dispatch to them |

## Flow

```
main
 └─ NotificationService::getInstance()          ← Singleton
     └─ NotificationObservable                  ← Subject (Observer pattern)
         ├─ Logger                              ← Observer — logs to console
         └─ NotificationEngine                  ← Observer — dispatches via strategies
             ├─ EmailStrategy
             ├─ SMSStrategy
             └─ PopUpStrategy

sendNotification(notification)
 └─ INotification (built with Decorators)       ← Decorator pattern
     └─ SignatureDecorator
         └─ TimeStampDecorator
             └─ SimpleNotification
```
