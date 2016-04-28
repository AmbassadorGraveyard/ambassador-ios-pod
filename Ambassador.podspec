Pod::Spec.new do |s|
   s.name = "Ambassador"
   s.platform = :ios
   s.version = "1.0.3"
   s.summary = "Ambassador Referral Marketing SDK for iOS"
   s.homepage = "https://www.getambassador.com"
   s.license = { :type => 'MIT' }
   s.author = { "Jake Dunahee" => "jake@getambassdor.com" }
   s.source = { :git => "https://github.com/GetAmbassador/ambassador-ios-pod.git" }
   s.frameworks = 'Ambassador'
   s.preserve_paths = 'Ambassador.framework'
   s.requires_arc = true
   s.resources = 'Ambassador.bundle'
   s.xcconfig = { 'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/Ambassador"' }
   s.source_files = 'Ambassador.framework/Headers/*'
end
