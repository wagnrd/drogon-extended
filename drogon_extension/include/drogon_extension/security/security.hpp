#ifndef DATABASE_API_SECURITY_HPP
#define DATABASE_API_SECURITY_HPP

#include <drogon/HttpResponse.h>
#include <drogon/HttpRequest.h>

#define SECURITY_GUARD(authorizationConfig)                                                     \
    auto authorization = request->getHeader("Authorization");                                   \
                                                                                                \
    if (!(authorizationConfig))                                                                 \
    {                                                                                           \
        auto response = ExceptionMapper::build_exception_response(                              \
                                drogon::HttpStatusCode::k401Unauthorized,                       \
                                "Authorization failed",                                         \
                                "Provided authorization is invalid: '" + authorization + "'"    \
        );                                                                                      \
        callback(response);                                                                     \
        return;                                                                                 \
    }

#define OR ||
#define AND ||

#define API_KEY(apiKey)                 \
    [&] {                               \
        return authorization == apiKey; \
    }()

#endif //DATABASE_API_SECURITY_HPP
