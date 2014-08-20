//
//  WeatherHTTPClient.h
//  Weather
//
//  Created by Charles Liu on 2014-08-20.
//  Copyright (c) 2014 Scott Sherwood. All rights reserved.
//

#import "AFHTTPSessionManager.h"
#import "AFHTTPSessionManager.h"

@protocol WeatherHTTPClientDelegate;

@interface WeatherHTTPClient : AFHTTPSessionManager

@property (nonatomic, weak) id <WeatherHTTPClientDelegate> delegate;

+ (WeatherHTTPClient *)sharedWeatherHTTPClient;
- (instancetype)initWithBaseURL:(NSURL *)url;
- (void)updateWeatherAtLocation:(CLLocation *)location forNumberOfDays:(NSUInteger)number;

@end


@protocol WeatherHTTPClientDelegate <NSObject>

@optional

- (void)weatherHTTPClient:(WeatherHTTPClient *)client didUpdateWithWeather:(id)weather;
- (void)weatherHTTPClient:(WeatherHTTPClient *)client didFailWithError:(NSError *)error;

@end
