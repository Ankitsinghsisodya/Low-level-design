#include "models/SimpleNotification.h"
#include "decorators/TimeStampDecorator.h"
#include "decorators/SignatureDecorator.h"
#include "observers/Logger.h"
#include "observers/NotificationEngine.h"
#include "strategies/EmailStrategy.h"
#include "strategies/SMSStrategy.h"
#include "strategies/PopUpStrategy.h"
#include "services/NotificationService.h"

int main()
{
    NotificationService *notificationService = NotificationService::getInstance();

    Logger *logger = new Logger();
    NotificationEngine *notificationEngine = new NotificationEngine();

    notificationEngine->addNotificationStrategy(new EmailStrategy("ankitsingh24012005@gmail.com"));
    notificationEngine->addNotificationStrategy(new SMSStrategy("7667144864"));
    notificationEngine->addNotificationStrategy(new PopUpStrategy());

    notificationObservable->addObserver(logger);
    notificationObservable->addObserver(notificationEngine);

    INotification *notification = new SimpleNotification("Your order has been shipped!");
    notification = new TimeStampDecorator(notification);
    notification = new SignatureDecorator(notification, "ankit sisodya");

    notificationService->sendNotification(notification);

    delete logger;
    delete notificationEngine;
    return 0;
}
