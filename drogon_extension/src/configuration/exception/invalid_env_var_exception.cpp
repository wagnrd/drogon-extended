#include <utility>
#include <drogon_extension/configuration/exceptions/invalid_env_var_exception.hpp>

InvalidEnvVarException::InvalidEnvVarException(std::string envVarName)
        : runtime_error("Environment variable '" + envVarName + "' is not set or invalid!"),
          envVarName(std::move(envVarName))
{}

const char* InvalidEnvVarException::what() const noexcept
{
    return runtime_error::what();
}

