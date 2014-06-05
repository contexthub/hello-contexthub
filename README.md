# Hello Context Hub
========================

The "Hello ContextHub" sample app that introduces you to the features of the ContextHub iOS SDK and developer portal

## Purpose

Today's world is full of devices and sensors just waiting to be tapped into. Meaningful events happen all the time, when we get home from work, approach an interesting painting, or visit our favorite coffee shop. ContextHub takes those meaningful events in our lives and transforms them into powerful triggers your apps can respond to turn apps into experiences for your end users. 

In this sample application, we use ContextHub introduce the relationship between devices triggering events on the server by setting up geofences on a map. 

## ContextHub

ContextHub takes care of setting up and monitoring geofences to generate events to server can listen and respond to.

## Getting Started

1. Get started by either forking or cloning the Hello ContextHub repo. Visit [GitHub Help](https://help.github.com/articles/fork-a-repo) if you need help.
2. Go to [ContextHub](http://app.contexthub.com) and find the app id associated with the "Hello World" app. Its format looks something like this: `13e7e6b4-9f33-4e97-b11c-79ed1470fc1d`.
3. Open up your Xcode project and put the app id into the `[ContextHub registerWithAppId:]` method call.
4. Build and run the project in the simulator.

## Xcode Console
1. This sample demo will log events into the debug console to get an idea of the JSON structure posted to ContextHub. Use shortcut `Shift-⌘-Y` if your console is not already visible.
2. When the app is launched, it should generate a `"location_changed"` event in the console which you can look at. You are able to access information about the event like device name, device ID, latitude, longitude, and speed.
3. Within the application delegate are 4 methods defined by the `CCHContextEventManagerDelegate` and `CCHContextEventManagerDataSource` which allow you hook into the event pipeline of events generated by ContextHub. you can get notified when an event will post and has been posted, as well as control if an event should be posted and add extra paylod data to an event. These 4 methods allow a lot of flexibility in controlling what events get sent to the server for additional processing.
4. Check out the ContextHub [documentation](http://docs.contexthub.com/#dictionary-samples) for more information about the event pipeline and what you can do with it. 

    
## ContextHub.com

1. The real power of ContextHub comes from collecting and reacting to events posted from devices onto the server. Go back to the [developer portal](http://app.contexthub.com) and click on your app "Hello World" to access its data.
2. You are then brought to the "Contexts" page which controls how the ContextHub server responds to events generated from devices. To the left you'll see "Contexts", which are rules which allow actions to be triggered depending on event data. To the right, you'll see your latest events triggered by devices with your app installed.


## Context Rules

Context rules let you change how the server will respond to events triggered by devices. Let's go ahead and create a new rule that will save the some data on the server in the vault.


## Creating a New Rule

1. In the "Contexts" tab, click the "NEW CONTEXT" button to start making a new rule.
2. Enter a name for this context which will be easy for you to remember. For now, name it "Geofence in".
3. Change the event type to `"geofence_in"`. Now any event of type `"geofence_in"` will trigger this rule. You can have multiple rules with the same event type, which is why name of events should be descriptive of the rule.
4. Below at the left is where you can write a rule telling ContextHub what actions to take in response to an event triggered with a specific event type. This code is Javascript, and you have access to 3 objects: event, push and vault. For now, click on the dropdown box and select `"Always execute"` then click save.
5. Back in XCode, stop and restart the simulator.
6. Simulate a location change in the device to one of the major cities XCode provides (click on the compass arrow in the debug controls area of XCode in the bottom). Zoom in as closely as possible to street level where the location circle appears on the map.
7. Tap the "Create Geofence" button to see a geofence appear on the map. You should also see a Fence creation event in the XCode console. If the simulated location is outside of the geofence circle, move the map around until the circle is centered on the screen and try again.
8. Change the simulated location again in XCode to be another major city. You should see a `"geofence_out"` event posted in the console. If you are having issues with events not being generated, see the note at the bottom for help.
9. Change the simulated location in XCode back to where you previously were and you should see a `"geofence_in"` event trigger as well.
10. In the ContextHub [developer portal](http://app.contexthub.com), you should be able to see events generated by your device appear under "Latest events", no code needed!


## Use the vault object in the context rule

Now that we've gotten the app to trigger events that both appear on the device and the server, it's time to create a rule that does something with that event.

1. Go back to "Contexts" and click on the `"location_changed"` context.
2. This page is where you previously set the rule related to `"geofence_in"` to `"Always execute"`. Instead, let's save the event data to the vault using Javascript.
3. Like stated previously, context rules have access to 3 objects: events, push, and vault. Events contain data about the event which triggered the rule. Push lets you send push notifications to devices. And the vault object lets you persist data on the server for retrieval later. Take a look at the vault object by clicking on it and seeing what methods it has access to.
4. In order to create an object in the vault, we need to store it in a container. A container holds similarly related vault items in a group for ease of access. To save the event object in a vault called "sample", type `vault.create("sample", event)` into the dropdown then click save.
5. Restart the simulator again, check and see if a `"location_changed"` event was generated, then go back to the developer portal to see if the event appeared in "Latest Events" under "Contexts".
6. Now click on "Vault" at the top to see if a "sample" container with an item with event data was created. Each time the `"location_changed"` event is received by ContextHub, it will create a new item in the vault for you to access based on the rule you just created.
7. That's all it takes to create a rule and put data into the vault!


## Trouble with the simulator
- If you hare having trouble with your location not appearing on the simulator, make sure you have the simulator set to use a custom location. Go to Debug-> Location, and set it to "Custom" to allow XCode to trigger changes manually.
- You can use the "Freeway" option to trigger "location_changed" events in your app as well.
